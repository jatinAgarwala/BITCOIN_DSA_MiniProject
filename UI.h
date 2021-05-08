#ifndef __UI_H
#define __UI_H

int UI_AddUser(UsersArray UA, UserHashTable UHT);
void UI_Transact(BlockChain B, UsersArray UA, UserHashTable UHT);
void UI_Attack(BlockChain B);
int UI_ValidateBlockChain(BlockChain B);
void UI_PrintCurrentBlockInfo(BlockChain B);
void UI_PrintInfoBlock(BlockChain B);
void UI_PrintUserInfo(UsersArray UA , UserHashTable UHT);
void UI_PrintAll_UIDs(UsersArray UA);
void UI_PrintNumBlocks(BlockChain B);

#endif
