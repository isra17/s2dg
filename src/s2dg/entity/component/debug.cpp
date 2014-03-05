#include "debug.h"

using namespace s2dg::com;

const int Debug::CID = 0xfe24603a;
const std::string Debug::NAME = "Debug";

Debug::Debug() 
: Component(Debug::CID, Debug::NAME)
{
}


Debug::~Debug() {}


void Debug::update() {

}