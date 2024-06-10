#include "platform.h"

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>

#include <format>
#include <iostream>
#include <string>

using namespace std;
using llvm::LLVMContext;

int main() {
    try {
        platform_init();
        
        auto ctx = LLVMContext();

        cout << format("hi {}", "there") << endl;

        return 0;
    } catch (exception &x) {
        cout << "unhandled exception: " << x.what() << endl;
        return -1;
    }
}