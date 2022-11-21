// Copyright (c) 2017-2018 The H2hcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef H2HCOIN_RPC_RAWTRANSACTION_UTIL_H
#define H2HCOIN_RPC_RAWTRANSACTION_UTIL_H

class CBasicKeyStore;
class UniValue;
struct CMutableTransaction;

namespace interfaces {
class Chain;
} // namespace interfaces

/** Sign a transaction with the given keystore and previous transactions */
UniValue SignTransaction(interfaces::Chain& chain, CMutableTransaction& mtx, const UniValue& prevTxs, CBasicKeyStore *keystore, bool tempKeystore, const UniValue& hashType);

/** Create a transaction from univalue parameters */
CMutableTransaction ConstructTransaction(const UniValue& inputs_in, const UniValue& outputs_in, const UniValue& locktime, const UniValue& rbf);

#endif // H2HCOIN_RPC_RAWTRANSACTION_UTIL_H
