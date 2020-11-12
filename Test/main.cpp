#include <bits/stdc++.h>
#include <ostream>
#include <unordered_map>

using namespace std;

vector<string> split_string(string);

void print(std::vector<bool> vec){
    for(auto val : vec){
        std::cout << val << " ";
    }
    std::cout << "\n";
}
void print(std::vector<int> vec){
    for(auto val : vec){
        std::cout << val << " ";
    }
    std::cout << "\n";
}

struct SharedState{

        std::string model_;
        std::string company_;
        std::string brand_;

      SharedState(const std::string& model, const std::string& company, const std::string& brand):
      model_(model), company_(company), brand_(brand){
      }

    friend std::ostream& operator<<(std::ostream& os, const SharedState& ss){
        return os << ss.model_ << " " << ss.company_ << " " << ss.brand_ << "\n";
    }
};

struct UniqueState{

        std::string owner_;
        std::string plate_;

        UniqueState(const std::string& owner, const std::string& plate):
            owner_(owner), plate_(plate){  
            }

        friend std::ostream& operator<<(std::ostream& os, const UniqueState& us){
            return os << us.owner_ << " " << us.plate_ << "\n";
        }
};

class FlyWeight{
    private:
        SharedState* shared_state_;
    public:
        FlyWeight(SharedState* ss):shared_state_(new SharedState(*ss)){}
        FlyWeight(const FlyWeight& cpy):shared_state_(new SharedState(cpy.shared_state_){}
        ~FlyWeight(){
            delete shared_state_;
        }
        SharedState* getSharedSTate(){
            return shared_state_;
        }
        void inputUniqueState(const UniqueState& us){
            std::cout << "Displaying shared state " << (*shared_state_) << " and unique state" << us << "\n";
        }

};

class FlyWeightFactoy{
    private:
        std::unordered_map<std::string, FlyWeight> FlyWeights_;

        std::string GetKey(const FlyWeight& fs){
            return fs.model_ + "_" + fs.company_ + "_" + fs.brand_;
        }

    public:
        FlyWeightFactoy(std::initializer_list<SharedState> ss){
            for(auto s : ss){
                this->FlyWeights_.insert(std::make_pair<std::string , FlyWeight>(GetKey(s), FlyWeight(s));
            }
        }

        void ListFlyWeights(){
            std::cout << "I have " << this->FlyWeights_.size() << " objects\n";
            for(auto f : this->FlyWeights_){
                std::cout << f.first << "\n";
            }
        }

        FlyWeight* GetFlyWeight(const SharedState* s){
            std::string key = GetKey(s);
            if(this->FlyWeights_.GetKey(s) == this->FlyWeights_.end()){
                std::cout << "no FlyWeight object existing, creating a new one\n";
                this->FlyWeights_.insert(std::make_pair<std::string, FlyWeight>(GetKey(s), FlyWeight(s));
            }
            else{
                return this->FlyWeights_.at(key);
            }
        }

};


int main()
{
    FlyWeightFactoyy *factory = new FlyWeightFactoyy({{"Chevrolet", "Camaro2018", "pink"}, {"Mercedes Benz", "C300", "black"}, {"Mercedes Benz", "C500", "red"}, {"BMW", "M5", "red"}, {"BMW", "X6", "white"}});
    factory->ListFlyWeights();

    AddCarToPoliceDatabase(*factory,
                            "CL234IR",
                            "James Doe",
                            "BMW",
                            "M5",
                            "red");

    AddCarToPoliceDatabase(*factory,
                            "CL234IR",
                            "James Doe",
                            "BMW",
                            "X1",
                            "red");
    factory->ListFlyWeights();
    delete factory;

    return 0;
}
