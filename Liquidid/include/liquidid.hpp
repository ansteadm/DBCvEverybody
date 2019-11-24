//#pragma once
//
//#include <eosio/eosio.hpp>
//#include "../dappservices/multi_index.hpp"
//
//
///* add necessary liquidaccount / vram includes */
//#include "../dappservices/vaccounts.hpp"
//#include "../dappservices/ipfs.hpp"
//#include "../dappservices/multi_index.hpp"
//
//#define dappservices_actions() \
//  xsignal_dappservice_action \
//  ipfs_dappservice_actions
//#define dappservices_actions_commands() \
//  ipfs_svc_commands()
//#define contract_name() liquidid
//using std::string;
//
//using namespace std;
//using namespace eosio;
//
//contract_start()
//  public:
//
//	  liquidid() {}
//
//	  [[eosio::action]]
//	  char generateid();
//
//	  [[eosio::action]]
//	  auto savedata(string data);
//
//	  [[eosio::action]]
//	  auto retrievedata(string id)
//
//  private:
//
//	  struct[[eosio::table]] shardbucket{
//		std::vector<char> shard_uri;
//		uint64_t shard;
//		uint64_t primary_key() const { return shard }
//	  }
//
//		struct[[eosio::table]] userids{
//			name vaccount
//			string  id;
//			vector<string> userdata;
//			auto primary_key() const { return id.value; }
//	  };
//
//	  typedef dapp::multi_index<name("userids"), userids> userids_table;
//
//	  typedef eosio::multi_index<name(".userids"), userids> userids_table_abi;
//
//	  typedef eosio::multi_index<name("userids"), shardbucket> userids_table_abi;
//
//
//	  contract_end((init)(generateid)(savedata)(retrievedata)(xdcommit)()xvinit)
