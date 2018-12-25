#pragma execution_character_set("utf-8")
#include "pslot.h"

Pslot::Pslot(QString pid, bool st): pid(pid), st(st) {
    /* 车位分为 A、B、C、D、E 五个区，每个车位的车位号是 例如 “A01”
       每个区车位号 01-10, 车位号以 QString 类存储。
       状态信息以 bool 类型存储, 可用为 true, 不可用则为 false
    */
}

void Pslot::stChange(){ // [给外界的接口] 成员函数: 改变某车位的状态信息。
    this->st = !this->st; // 取反即可
}
