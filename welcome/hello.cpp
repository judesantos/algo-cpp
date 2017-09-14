#include "hello.h"

Hello::Hello(string msg) {
    this->msg = msg;
}

Hello::~Hello() {
    this->msg = "";
}

string Hello::sayHello() {
    return this->msg;
}
