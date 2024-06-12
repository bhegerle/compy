#include "ast/ident.h"
#include "ast/module.h"
#include "parser/fmt.h"
#include "parser/lexer.h"
#include "parser/token.h"

#include "platform.h"
//
// #include <llvm/ADT/APFloat.h>
// #include <llvm/ADT/STLExtras.h>
// #include <llvm/IR/BasicBlock.h>
// #include <llvm/IR/Constants.h>
// #include <llvm/IR/DerivedTypes.h>
// #include <llvm/IR/Function.h>
// #include <llvm/IR/IRBuilder.h>
// #include <llvm/IR/LLVMContext.h>
// #include <llvm/IR/Module.h>
// #include <llvm/IR/Type.h>
// #include <llvm/IR/Verifier.h>

#include <filesystem>
#include <format>
#include <iostream>
#include <string>

using namespace parser;
using namespace utils;
using namespace std;

using func = ast::func<string>;
using module = ast::module<func>;
using ast::ident;

using std::filesystem::path;

struct visitor {
    void visit(const module &m) {
        cout << format("module {}", m.name()) << endl;
        cout << string(80, '-') << endl;
    }

    void visit(const func &f) {}
};

class test_lexer {
  public:
    void push(string_view txt, token_type type = token_type::ws) {
        buffer += txt;
        sizes.push_back(txt.size());
        types.push_back(type);
    }

    vector<token> lex() const {
        auto f = make_shared<file_buf>(path("<test>"), buffer);
        return lexer(f, sizes, types).lex();
    }

  private:
    string buffer;
    vector<uint32_t> sizes;
    vector<token_type> types;

    class lexer : public lexer_base {
      public:
        lexer(shared_ptr<file_buf> f, vector<uint32_t> sizes,
              vector<token_type> types)
            : lexer_base(f), sizes(sizes), types(types) {}

        vector<token> lex() {
            auto v = vector<token>();
            for (uint32_t i = 0; i < sizes.size(); i++) {
                if (types[i] != token_type::ws)
                    v.push_back(take(sizes[i], types[i]));
                else
                    skip(sizes[i]);
            }

            return v;
        }

      private:
        vector<uint32_t> sizes;
        vector<token_type> types;
    };
};

int main() {
    try {
        platform_init();

        auto tlex = test_lexer();
        tlex.push(" ");
        tlex.push("x", token_type::ident);
        tlex.push(" ");

        for (auto &t : tlex.lex())
            cout << format("{}", t) << endl;

        auto f = file_buf(path(), "\nabc\ndef\n\nhij");
        cout << "1:" << f.line(1) << ":" << endl;
        cout << "2:" << f.line(2) << ":" << endl;
        cout << "3:" << f.line(3) << ":" << endl;
        cout << "4:" << f.line(4) << ":"<<endl;

        return 0;
    } catch (exception &x) {
        cout << "unhandled exception: " << x.what() << endl;
        return -1;
    }
}