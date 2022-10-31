#include "UserWithSubscriptionInterface.h"

UserWithSubscriptionInterface::UserWithSubscriptionInterface() : UserInterface() {}

UserWithSubscriptionInterface::~UserWithSubscriptionInterface() {
	UserInterface::~UserInterface();
}

void UserWithSubscriptionInterface::setTripsAmount(int amount) { this->tripsAmount = amount;}

int UserWithSubscriptionInterface::getTripsAmount() const { return this->tripsAmount; }

void UserWithSubscriptionInterface::interact() {
	//@Update
}

void UserWithSubscriptionInterface::interfaceMenu(){
	//@Update
}