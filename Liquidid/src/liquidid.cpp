//#include <liquidid.hpp>
//
//ACTION liquidid::generateID() {
//	// Will need to generate cryptographically random key using crypto++
//
//	// Set new vaccount
//	regaccount(userIds)
//}
//
//ACTION liquidid::saveData(userIds payload) {
//	require_vaccount(payload.vaccount);
//
//	messages_table _messages(get_self(), get_self().value);
//
//	// Delete all records in _messages table
//	auto msg_itr = _messages.begin();
//	while (msg_itr != _messages.end()) {
//		msg_itr = _messages.erase(msg_itr);
//	}
//}
//
//EOSIO_DISPATCH(dbctest, (hi)(clear))

#define VACCOUNTS_DELAYED_CLEANUP 120

#include "../dappservices/vaccounts.hpp"
#include "../dappservices/ipfs.hpp"
#include "../dappservices/multi_index.hpp"

#define DAPPSERVICES_ACTIONS() \
  XSIGNAL_DAPPSERVICE_ACTION \
  IPFS_DAPPSERVICE_ACTIONS \
  VACCOUNTS_DAPPSERVICE_ACTIONS
#define DAPPSERVICE_ACTIONS_COMMANDS() \
  IPFS_SVC_COMMANDS()VACCOUNTS_SVC_COMMANDS() 

#define CONTRACT_NAME() vaccountsconsumer 


CONTRACT_START()


struct dummy_action_hello {
	name vaccount;
	uint64_t b;
	uint64_t c;

	EOSLIB_SERIALIZE(dummy_action_hello, (vaccount)(b)(c))
};

[[eosio::action]] void hello(dummy_action_hello payload) {
	require_vaccount(payload.vaccount);

	print("hello from ");
	print(payload.vaccount);
	print(" ");
	print(payload.b + payload.c);
	print("\n");
}

[[eosio::action]] void hello2(dummy_action_hello payload) {
	print("hello2(default action) from ");
	print(payload.vaccount);
	print(" ");
	print(payload.b + payload.c);
	print("\n");
}

[[eosio::action]] void init(dummy_action_hello payload) {
}

VACCOUNTS_APPLY(((dummy_action_hello)(hello))((dummy_action_hello)(hello2)))

CONTRACT_END((init)(hello)(hello2)(regaccount)(xdcommit)(xvinit))