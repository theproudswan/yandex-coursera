#pragma once 

#include <memory>

namespace RAII {

    template <typename Provider>
    class Booking{
    public:
        Booking(Provider* provider, int id) : provider_(provider), id_(id) {}
        Booking(const Booking&) = delete;
        Booking(Booking&& other) {
            provider_ = other.provider_;
            id_ = other.id_;
            other.provider_ = nullptr;
        }
        Booking& operator= (const Booking&) = delete;
        Booking& operator= (Booking&& other) {
            provider_ = other.provider_;
            id_ = other.id_;
            other.provider_ = nullptr;
            return *this;
        }
        ~Booking(){
            if(provider_){
                provider_->CancelOrComplete(*this);
            }
        }
    private:
        //std::unique_ptr<Provider> provider_;
        Provider* provider_;
        int id_;
    };

} // end of namespace RAII