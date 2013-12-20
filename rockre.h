#ifndef ROCKRE_H_
#define ROCKRE_H_

#include <stddef.h>
#include <string>
#include <vector>

namespace RockRE {

  enum OPType {
    OP_HEAD,
    OP_TAIL,
    OP_CAPTURE,
    OP_SPLIT,
    OP_FINISH,
    OP_CHAR,
  };

  enum NodeType {
    NODE_UNDEF,
    NODE_LIST = 1,
    NODE_OR,
    NODE_TAIL,
    NODE_HEAD,
    NODE_STRING,
    NODE_CAPTURE,
    NODE_GROUP,
    NODE_ANYCHAR,
  };

  class Node {
    enum NodeType type_;
    std::string string_;
    std::vector<Node> children_;
  public:
    Node(const Node &node)
      : type_(node.type_), string_(node.string_), children_(node.children_) { }
    Node()
      : type_(NODE_UNDEF) { }
    Node(NodeType t)
      : type_(t) { }
    Node(NodeType t, std::string str)
      : type_(t), string_(str) { }
    Node(NodeType t, const char* s, size_t l)
      : type_(t), string_(s, l) { }
    Node(NodeType t, const Node& child)
      : type_(t) {
          children_.push_back(child);
      }
    Node(NodeType t, Node a, Node b)
      : type_(t) {
          children_.push_back(a);
          children_.push_back(b);
      }
    NodeType type() const {
      return type_;
    }
    std::string string() const {
      return string_;
    }
    const std::vector<Node>& children() const {
      return children_;
    }
    void push_child(Node b) {
      children_.push_back(b);
    }
    void dump() const;
    void dump_children(std::string name) const;
  };

  class Code {
  public:
    OPType op_;
    int c_;
    int x_;
    int y_;
  public:
    Code(OPType op)
      : op_(op), c_(0) { }
    Code(OPType op, const char c)
      : op_(op), c_(c) { }
    OPType op() const { return op_; }
    char c() const { return c_; }
  };

  class Irep {
    std::vector<Code> codes_;
  public:
    const Code* codes() const {
      return codes_.data();
    }
    void push(OPType op, const char c) {
      codes_.emplace_back(op, c);
    }
    void push(OPType op) {
      codes_.emplace_back(op);
    }
  };

  /* parser api */
  Node parse(const std::string str);
  void codegen(const Node& node, Irep& irep);

  bool match(const std::string str, const Irep& irep);

  // Code generator API
  // rockre_irep * rockre_codegen(rockre_node* node);
  // void rockre_irep_free(rockre_irep* irep);

};

/*
typedef struct rockre_code {
  rockre_op opcode;
  int c;
  struct rockre_code* x;
  struct rockre_code* y;
} rockre_code;

typedef struct rockre_irep {
    rockre_code** ops;
    size_t nops;
} rockre_irep;

// VM API
bool rockre_vm_run(const char *str, size_t len, rockre_irep* irep);
*/


#endif // ROCKRE_H_
