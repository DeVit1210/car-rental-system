#pragma once
#include"UserInterface.h"
class UserWithSubscriptionInterface : public UserInterface {
	//Subscription* subscriptionPtr;
	int tripsAmount;
public:
	UserWithSubscriptionInterface();
	//UserWithSubscriptionInterface(CarList* carListPtr, PersonalData* personalDataPtr, interfaceType type, IdentityData* identityDataPtr);
	~UserWithSubscriptionInterface();
	void interact();
	void setTripsAmount(int tripsAmount);
	int getTripsAmount() const;
	void interfaceMenu();
	//float getCostOfTrip(Car* rentedCar, int amountOfHours);
};

