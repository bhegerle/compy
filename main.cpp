#include "ast/ident.h"
#include "ast/module.h"
#include "parser/fmt.h"
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
    test_lexer() : p("<test>"), line(1), col(1) { buffer.reserve(20000); }

    void push(string_view ws) { append(ws); }

    void push(string_view txt, token_type type) {
        auto loc = txt_loc(p, line, col);
        auto atxt = append(txt);
        tokens.emplace_back(make_shared<token>(type, atxt, loc));
    }

    auto begin() const { return tokens.begin(); }
    auto end() const { return tokens.end(); }
    auto &operator[](size_t i) { return tokens[i]; }

  private:
    path p;
    string buffer;
    uint32_t line, col;
    vector<shared_ptr<token>> tokens;

    string_view append(string_view txt) {
        if (buffer.size() + txt.size() > buffer.capacity())
            throw runtime_error("test_lexer buffer capacity exceeded");

        auto n = buffer.size();
        buffer.append(txt.begin(), txt.end());

        for (auto c : txt) {
            if (c == '\n') {
                line++;
                col = 1;
            } else {
                col++;
            }
        }

        return string_view(buffer).substr(n, txt.size());
    }
};

int main() {
    try {
        platform_init();

        auto lex = test_lexer();
        lex.push(" ");
        lex.push("x", token_type::ident);
        lex.push(" ");

        for (auto &t : lex)
            cout << format("{}", *t) << endl;

        auto id = ident(lex[0]);

        return 0;
    } catch (exception &x) {
        cout << "unhandled exception: " << x.what() << endl;
        return -1;
    }
}