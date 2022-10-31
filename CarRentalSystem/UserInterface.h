#pragma once
#include"Interface.h"
#include"IdentityData.h"
#include<fstream>
#include"PersonalData.h"

class UserInterface : public Interface {
protected:
	//CarOrderScreen* carOrderPtr;
	//AccountReplenishmentScreen* accountReplenishmentPtr;
	//SubscriptionMakingScreen* subscriptionScreenPtr;
	shared_ptr<IdentityData> identityDataPtr;
	shared_ptr<PersonalData> personalDataPtr;
public:
	UserInterface();
	UserInterface(shared_ptr<IdentityData> identityDataPtr, shared_ptr<PersonalData> personalDataPtr);
	//UserInterface(CarList* carListPtr, PersonalData* personalDataPtr, interfaceType type, IdentityData* identityDataPtr);
	~UserInterface();
	void interact() override;
	void interfaceMenu() override;
	void write(ofstream& fout) override;
	void read(ifstream& fin) override;
	
	//float getCostOfTrip(Car* rentedCar, int amountOfHours);
};
