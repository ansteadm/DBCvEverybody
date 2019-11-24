#include <liquidid.hpp>

ACTION liquidid::generateID() {
	// Will need to generate cryptographically random key using crypto++

	// Set new vaccount
	regaccount(userIds)
}

ACTION liquidid::saveData(userids payload, string data) {
	require_vaccount(payload.vaccount);

	// Push data into payload's vector
	payload.userdata.push_back(data);

	return payload
}

ACTION liquidid::retrieveData(userids payload) {
	require_vaccount(payload.vaccount);

	// Get account with vector data
	getKey(payload.vaccount)

	return payload
}

EOSIO_DISPATCH(liquidid, (generateID)(saveData)(retrieveData))
