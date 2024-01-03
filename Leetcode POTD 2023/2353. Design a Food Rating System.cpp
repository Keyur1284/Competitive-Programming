// Problem Link :- https://leetcode.com/problems/design-a-food-rating-system/

// Solved using unordered_map and priority_queue (with operator overloading)
// Time Complexity :- O(n * logn + m * log(n + m))      n = number of foods
// Space Complexity :- O(n + m)                         m = number of calls to highestRated() and changeRating()

class Food {
public:

    int foodRating;
    string foodName;

    Food (int foodRating, string foodName) 
    {
        this->foodRating = foodRating;
        this->foodName = foodName;
    }

    bool operator<(const Food& other) const 
    {
        if (foodRating == other.foodRating)
            return foodName > other.foodName;

        return foodRating < other.foodRating;
    }
};

class FoodRatings {

    unordered_map<string, int> foodRatingMap;
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, priority_queue<Food>> cuisineFoodMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        int n = foods.size();

        for (int i = 0; i < n; i++) 
        {
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            cuisineFoodMap[cuisines[i]].push(Food(ratings[i], foods[i]));
        }
    } 
    
    void changeRating(string food, int newRating) {

        foodRatingMap[food] = newRating;
        auto cuisineName = foodCuisineMap[food];
        cuisineFoodMap[cuisineName].push(Food(newRating, food));
    }
    
    string highestRated(string cuisine) {

        auto highestRated = cuisineFoodMap[cuisine].top();
       
        while (foodRatingMap[highestRated.foodName] != highestRated.foodRating) 
        {
            cuisineFoodMap[cuisine].pop();
            highestRated = cuisineFoodMap[cuisine].top();
        }

        return highestRated.foodName;
    }
};



// Solved using unordered_map and priority_queue (with custom comparator)
// Time Complexity :- O(n * logn + m * log(n + m))      n = number of foods
// Space Complexity :- O(n + m)                         m = number of calls to highestRated() and changeRating()

class Food {
public:

    int foodRating;
    string foodName;

    Food (int foodRating, string foodName) 
    {
        this->foodRating = foodRating;
        this->foodName = foodName;
    }
};

class Comparator {
public:

    bool operator()(const Food &f1, const Food &f2)
    {
        if (f1.foodRating == f2.foodRating)
            return f1.foodName > f2.foodName;

        return f1.foodRating < f2.foodRating;
    }
};

class FoodRatings {

    unordered_map<string, int> foodRatingMap;
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, priority_queue<Food, vector<Food>, Comparator>> cuisineFoodMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        int n = foods.size();

        for (int i = 0; i < n; i++) 
        {
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            cuisineFoodMap[cuisines[i]].push(Food(ratings[i], foods[i]));
        }
    } 
    
    void changeRating(string food, int newRating) {

        foodRatingMap[food] = newRating;
        auto cuisineName = foodCuisineMap[food];
        cuisineFoodMap[cuisineName].push(Food(newRating, food));
    }
    
    string highestRated(string cuisine) {

        auto highestRated = cuisineFoodMap[cuisine].top();
       
        while (foodRatingMap[highestRated.foodName] != highestRated.foodRating) 
        {
            cuisineFoodMap[cuisine].pop();
            highestRated = cuisineFoodMap[cuisine].top();
        }

        return highestRated.foodName;
    }
};



// Solved using unordered_map and set
// Time Complexity :- O((n + m) * logn)      n = number of foods
// Space Complexity :- O(n)                  m = number of calls to highestRated() and changeRating()

class FoodRatings {

    unordered_map<string, int> foodRatingMap;
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, set<pair<int, string>>> cuisineFoodMap;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {

        int n = foods.size();

        for (int i = 0; i < n; i++) 
        {
            foodRatingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            cuisineFoodMap[cuisines[i]].insert({ -ratings[i], foods[i] });
        }
    } 

    void changeRating(string food, int newRating) {

        auto cuisineName = foodCuisineMap[food];

        auto oldElementIterator = cuisineFoodMap[cuisineName].find({ -foodRatingMap[food], food });
        cuisineFoodMap[cuisineName].erase(oldElementIterator);

        foodRatingMap[food] = newRating;
        cuisineFoodMap[cuisineName].insert({ -newRating, food });
    }
    
    string highestRated(string cuisine) {
        
        auto highestRated = *cuisineFoodMap[cuisine].begin();
        return highestRated.second;
    }
};