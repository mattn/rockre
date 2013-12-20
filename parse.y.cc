/* A recursive-descent parser generated by greg 0.4.4 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct _GREG;
#define YYRULECOUNT 11


#include "rockre.h"
#include <assert.h>
#include <memory>

/**

aaa|bbb

*/

using namespace RockRE;

#define YYSTYPE RockRE::Node
#define YY_NAME(n) rockre_parser_##n
#define YY_XTYPE RockRE::ParserContext

#define PARSER (&(G->data))

namespace RockRE {
  class ParserInput {
    friend class ParserContext;
    std::string src_;
    size_t pos_;
  public:
    ParserInput(std::string &s) {
      src_ = s;
      pos_ = 0;
    }
  };

  class ParserContext {
    Node root_;
    ParserInput* input_;
  public:
    void input(ParserInput* input) {
      input_ = input;
    }
    void root(const Node& root) {
      root_ = root;
    }
    Node root() const {
      return root_;
    }
    char yy_input(char* buf) {
      if (input_->src_.length() == input_->pos_) {
        return 0;
      } else {
        *buf = input_->src_[input_->pos_];
        input_->pos_ = input_->pos_+1;
        return 1;
      }
    }
  };
};

#define YY_INPUT(buf, result, max_size, D)		\
    result = D.yy_input(buf);

// TODO: <[abc]>
// TODO: ( a | b )

#define S Node


#ifndef YY_ALLOC
#define YY_ALLOC(N, D) malloc(N)
#endif
#ifndef YY_CALLOC
#define YY_CALLOC(N, S, D) calloc(N, S)
#endif
#ifndef YY_REALLOC
#define YY_REALLOC(B, N, D) realloc(B, N)
#endif
#ifndef YY_FREE
#define YY_FREE free
#endif
#ifndef YY_LOCAL
#define YY_LOCAL(T)     static T
#endif
#ifndef YY_ACTION
#define YY_ACTION(T)    static T
#endif
#ifndef YY_RULE
#define YY_RULE(T)      static T
#endif
#ifndef YY_PARSE
#define YY_PARSE(T)     T
#endif
#ifndef YY_NAME
#define YY_NAME(N) yy##N
#endif
#ifndef YY_INPUT
#define YY_INPUT(buf, result, max_size, D)		\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#ifndef YY_BEGIN
#define YY_BEGIN        ( G->begin= G->pos, 1)
#endif
#ifndef YY_END
#define YY_END          ( G->end= G->pos, 1)
#endif
#ifdef YY_DEBUG
# ifndef DEBUG_PARSE
#  define DEBUG_PARSE   1
# endif
# ifndef DEBUG_VERBOSE
#  define DEBUG_VERBOSE 2
# endif
# define yyprintf(args)	         if (G->debug & DEBUG_PARSE)         fprintf args
# define yyprintfv(args)         if (G->debug == (DEBUG_PARSE|DEBUG_VERBOSE)) fprintf args
# define yyprintfGcontext        if (G->debug & DEBUG_PARSE)         yyprintcontext(stderr,G->buf+G->pos)
# define yyprintfvGcontext       if (G->debug == (DEBUG_PARSE|DEBUG_VERBOSE)) yyprintcontext(stderr,G->buf+G->pos)
# define yyprintfvTcontext(text) if (G->debug == (DEBUG_PARSE|DEBUG_VERBOSE)) yyprintcontext(stderr,text)
#else
# define yyprintf(args)
# define yyprintfv(args)
# define yyprintfGcontext
# define yyprintfvGcontext
# define yyprintfvTcontext(text)
#endif
#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YY_XTYPE
#define YY_XTYPE void *
#endif
#ifndef YY_XVAR
#define YY_XVAR yyxvar
#endif

#ifndef YY_STACK_SIZE
#define YY_STACK_SIZE 128
#endif

#ifndef YY_BUFFER_START_SIZE
#define YY_BUFFER_START_SIZE 1024
#endif

#ifndef YY_PART
#define yydata G->data
#define yy G->ss

struct _yythunk; /* forward declaration */
typedef void (*yyaction)(struct _GREG *G, char *yytext, int yyleng, struct _yythunk *thunkpos, YY_XTYPE YY_XVAR);
typedef struct _yythunk { int begin, end;  yyaction  action; const char *name; struct _yythunk *next; } yythunk;

typedef struct _GREG {
  char *buf;
  int buflen;
  int   offset;
  int   pos;
  int   limit;
  char *text;
  int   textlen;
  int   begin;
  int   end;
  yythunk *thunks;
  int   thunkslen;
  int thunkpos;
  YYSTYPE ss;
  YYSTYPE *val;
  YYSTYPE *vals;
  int valslen;
  YY_XTYPE data;
#ifdef YY_DEBUG
  int debug;
#endif
} GREG;

YY_LOCAL(int) yyrefill(GREG *G)
{
  int yyn;
  while (G->buflen - G->pos < 512)
    {
      G->buflen *= 2;
      G->buf= (char*)YY_REALLOC(G->buf, G->buflen, G->data);
    }
  YY_INPUT((G->buf + G->pos), yyn, (G->buflen - G->pos), G->data);
  if (!yyn) return 0;
  G->limit += yyn;
  return 1;
}

YY_LOCAL(int) yymatchDot(GREG *G)
{
  if (G->pos >= G->limit && !yyrefill(G)) return 0;
  ++G->pos;
  return 1;
}

#ifdef YY_DEBUG
YY_LOCAL(void) yyprintcontext(FILE *stream, char *s)
{
  char *context = s;
  char *nl = strchr(context, 10);
  if (nl) {
    context = (char*)malloc(nl-s+1);
    strncpy(context, s, nl-s);
    context[nl-s] = '\0'; /* replace nl by 0 */
  }
  fprintf(stream, " @ \"%s\"", context);
  if (nl) free(context);
}
#endif

YY_LOCAL(int) yymatchChar(GREG *G, int c)
{
  if (G->pos >= G->limit && !yyrefill(G)) return 0;
  if ((unsigned char)G->buf[G->pos] == c)
    {
      ++G->pos;
      if (c<32) { yyprintf((stderr, "  ok   yymatchChar '0x%x'", c));}
      else      { yyprintf((stderr, "  ok   yymatchChar '%c'", c));}
      yyprintfGcontext;
      yyprintf((stderr, "\n"));
      return 1;
    }
  if (c<32) { yyprintfv((stderr, "  fail yymatchChar '0x%x'", c));}
  else      { yyprintfv((stderr, "  fail yymatchChar '%c'", c));}
  yyprintfvGcontext;
  yyprintfv((stderr, "\n"));
  return 0;
}

YY_LOCAL(int) yymatchString(GREG *G, const char *s)
{
  int yysav= G->pos;
  while (*s)
    {
      if (G->pos >= G->limit && !yyrefill(G)) return 0;
      if (G->buf[G->pos] != *s)
        {
          G->pos= yysav;
          return 0;
        }
      ++s;
      ++G->pos;
    }
  return 1;
}

YY_LOCAL(int) yymatchClass(GREG *G, const unsigned char *bits, const char *cclass)
{
  int c;
  if (G->pos >= G->limit && !yyrefill(G)) return 0;
  c= (unsigned char)G->buf[G->pos];
  if (bits[c >> 3] & (1 << (c & 7)))
    {
      ++G->pos;
      yyprintf((stderr, "  ok   yymatchClass [%s]", cclass));
      yyprintfGcontext;
      yyprintf((stderr, "\n"));
      return 1;
    }
  yyprintfv((stderr, "  fail yymatchClass [%s]", cclass));
  yyprintfvGcontext;
  yyprintfv((stderr, "\n"));
  return 0;
}

YY_LOCAL(void) yyDo(GREG *G, yyaction action, int begin, int end, const char *name)
{
  while (G->thunkpos >= G->thunkslen)
    {
      G->thunkslen *= 2;
      G->thunks= (yythunk*)YY_REALLOC(G->thunks, sizeof(yythunk) * G->thunkslen, G->data);
    }
  G->thunks[G->thunkpos].begin=  begin;
  G->thunks[G->thunkpos].end=    end;
  G->thunks[G->thunkpos].action= action;
  G->thunks[G->thunkpos].name= name;
  ++G->thunkpos;
}

YY_LOCAL(int) yyText(GREG *G, int begin, int end)
{
  int yyleng= end - begin;
  if (yyleng <= 0)
    yyleng= 0;
  else
    {
      while (G->textlen < (yyleng + 1))
        {
          G->textlen *= 2;
          G->text= (char*)YY_REALLOC(G->text, G->textlen, G->data);
        }
      memcpy(G->text, G->buf + begin, yyleng);
    }
  G->text[yyleng]= '\0';
  return yyleng;
}

YY_LOCAL(void) yyDone(GREG *G)
{
  int pos;
  for (pos= 0; pos < G->thunkpos; ++pos)
    {
      yythunk *thunk= &G->thunks[pos];
      int yyleng= thunk->end ? yyText(G, thunk->begin, thunk->end) : thunk->begin;
      yyprintf((stderr, "DO [%d] %s", pos, thunk->name));
      yyprintfvTcontext(G->text);
      yyprintf((stderr, "\n"));
      thunk->action(G, G->text, yyleng, thunk, G->data);
    }
  G->thunkpos= 0;
}

YY_LOCAL(void) yyCommit(GREG *G)
{
  if ((G->limit -= G->pos))
    {
      memmove(G->buf, G->buf + G->pos, G->limit);
    }
  G->offset += G->pos;
  G->begin -= G->pos;
  G->end -= G->pos;
  G->pos= G->thunkpos= 0;
}

YY_LOCAL(int) yyAccept(GREG *G, int tp0)
{
  if (tp0)
    {
      fprintf(stderr, "accept denied at %d\n", tp0);
      return 0;
    }
  else
    {
      yyDone(G);
      yyCommit(G);
    }
  return 1;
}

YY_LOCAL(void) yyPush(GREG *G, char *text, int count, yythunk *thunk, YY_XTYPE YY_XVAR)	{
  size_t off = (G->val - G->vals) + count;
  if (off > G->valslen) {
    while (G->valslen < off + 1)
      G->valslen *= 2;
    G->vals= (YYSTYPE*)YY_REALLOC((void *)G->vals, sizeof(YYSTYPE) * G->valslen, G->data);
    G->val= G->vals + off;
  } else {
    G->val += count;
  }
}
YY_LOCAL(void) yyPop(GREG *G, char *text, int count, yythunk *thunk, YY_XTYPE YY_XVAR)	{ G->val -= count; }
YY_LOCAL(void) yySet(GREG *G, char *text, int count, yythunk *thunk, YY_XTYPE YY_XVAR)	{ G->val[count]= G->ss; }

#endif /* YY_PART */

#define YYACCEPT        yyAccept(G, yythunkpos0)

YY_RULE(int) yy_esc(GREG *G); /* 11 */
YY_RULE(int) yy_raw_part(GREG *G); /* 10 */
YY_RULE(int) yy_raw(GREG *G); /* 9 */
YY_RULE(int) yy_tail(GREG *G); /* 8 */
YY_RULE(int) yy_head(GREG *G); /* 7 */
YY_RULE(int) yy_term(GREG *G); /* 6 */
YY_RULE(int) yy_terms(GREG *G); /* 5 */
YY_RULE(int) yy_end_of_file(GREG *G); /* 4 */
YY_RULE(int) yy_pattern(GREG *G); /* 3 */
YY_RULE(int) yy__(GREG *G); /* 2 */
YY_RULE(int) yy_rockre(GREG *G); /* 1 */

YY_ACTION(void) yy_1_tail(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
  yyprintf((stderr, "do yy_1_tail"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {yy = S(RockRE::NODE_TAIL); }\n"));
  yy = S(RockRE::NODE_TAIL); ;
}
YY_ACTION(void) yy_1_head(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
  yyprintf((stderr, "do yy_1_head"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {yy = S(RockRE::NODE_HEAD); }\n"));
  yy = S(RockRE::NODE_HEAD); ;
}
YY_ACTION(void) yy_3_raw_part(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
  yyprintf((stderr, "do yy_3_raw_part"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {yy = S(RockRE::NODE_STRING, \"\\t\", 1); }\n"));
  yy = S(RockRE::NODE_STRING, "\t", 1); ;
}
YY_ACTION(void) yy_2_raw_part(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
  yyprintf((stderr, "do yy_2_raw_part"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {yy = S(RockRE::NODE_STRING, \".\", 1); }\n"));
  yy = S(RockRE::NODE_STRING, ".", 1); ;
}
YY_ACTION(void) yy_1_raw_part(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
  yyprintf((stderr, "do yy_1_raw_part"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {yy = S(RockRE::NODE_STRING, yytext, yyleng); }\n"));
  yy = S(RockRE::NODE_STRING, yytext, yyleng); ;
}
YY_ACTION(void) yy_3_raw(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
#define b G->val[-1]
#define a G->val[-2]
  yyprintf((stderr, "do yy_3_raw"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {yy = a; }\n"));
  yy = a; ;
#undef b
#undef a
}
YY_ACTION(void) yy_2_raw(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
#define b G->val[-1]
#define a G->val[-2]
  yyprintf((stderr, "do yy_2_raw"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {\n\
      a = S(RockRE::NODE_STRING, a.string() + b.string());\n\
    }\n"));
  
      a = S(RockRE::NODE_STRING, a.string() + b.string());
    ;
#undef b
#undef a
}
YY_ACTION(void) yy_1_raw(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
#define b G->val[-1]
#define a G->val[-2]
  yyprintf((stderr, "do yy_1_raw"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {yy = a; }\n"));
  yy = a; ;
#undef b
#undef a
}
YY_ACTION(void) yy_3_term(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
#define a G->val[-1]
  yyprintf((stderr, "do yy_3_term"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {yy = S(RockRE::NODE_ANYCHAR); }\n"));
  yy = S(RockRE::NODE_ANYCHAR); ;
#undef a
}
YY_ACTION(void) yy_2_term(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
#define a G->val[-1]
  yyprintf((stderr, "do yy_2_term"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {yy = S(RockRE::NODE_GROUP, a); }\n"));
  yy = S(RockRE::NODE_GROUP, a); ;
#undef a
}
YY_ACTION(void) yy_1_term(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
#define a G->val[-1]
  yyprintf((stderr, "do yy_1_term"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {yy = S(RockRE::NODE_CAPTURE, a); }\n"));
  yy = S(RockRE::NODE_CAPTURE, a); ;
#undef a
}
YY_ACTION(void) yy_3_terms(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
#define b G->val[-1]
#define a G->val[-2]
  yyprintf((stderr, "do yy_3_terms"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {yy = a; }\n"));
  yy = a; ;
#undef b
#undef a
}
YY_ACTION(void) yy_2_terms(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
#define b G->val[-1]
#define a G->val[-2]
  yyprintf((stderr, "do yy_2_terms"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {\n\
            if (a.type() != RockRE::NODE_LIST) {\n\
                a = S(RockRE::NODE_LIST, a);\n\
            }\n\
            a.push_child(b);\n\
        }\n"));
  
            if (a.type() != RockRE::NODE_LIST) {
                a = S(RockRE::NODE_LIST, a);
            }
            a.push_child(b);
        ;
#undef b
#undef a
}
YY_ACTION(void) yy_1_terms(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
#define b G->val[-1]
#define a G->val[-2]
  yyprintf((stderr, "do yy_1_terms"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {yy = a; }\n"));
  yy = a; ;
#undef b
#undef a
}
YY_ACTION(void) yy_1_pattern(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
#define b G->val[-1]
#define a G->val[-2]
  yyprintf((stderr, "do yy_1_pattern"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {\n\
      yy = S(RockRE::NODE_OR, a, b);\n\
    }\n"));
  
      yy = S(RockRE::NODE_OR, a, b);
    ;
#undef b
#undef a
}
YY_ACTION(void) yy_1_rockre(GREG *G, char *yytext, int yyleng, yythunk *thunk, YY_XTYPE YY_XVAR)
{
#define a G->val[-1]
  yyprintf((stderr, "do yy_1_rockre"));
  yyprintfvTcontext(yytext);
  yyprintf((stderr, "\n  {yy = a; G->data.root(a); }\n"));
  yy = a; G->data.root(a); ;
#undef a
}

YY_RULE(int) yy_esc(GREG *G)
{  int yypos0= G->pos, yythunkpos0= G->thunkpos;  yyprintfv((stderr, "%s\n", "esc"));
  if (!yymatchChar(G, '\\')) goto l1;
  yyprintf((stderr, "  ok   esc"));
  yyprintfGcontext;
  yyprintf((stderr, "\n"));

  return 1;
  l1:;	  G->pos= yypos0; G->thunkpos= yythunkpos0;  yyprintfv((stderr, "  fail %s", "esc"));
  yyprintfvGcontext;
  yyprintfv((stderr, "\n"));

  return 0;
}
YY_RULE(int) yy_raw_part(GREG *G)
{  int yypos0= G->pos, yythunkpos0= G->thunkpos;  yyprintfv((stderr, "%s\n", "raw_part"));

  {  int yypos3= G->pos, yythunkpos3= G->thunkpos;  yyText(G, G->begin, G->end);  if (!(YY_BEGIN)) goto l4;  if (!yymatchClass(G, (const unsigned char *)"\377\377\377\377\376\274\377\377\377\377\377\307\377\377\377\357\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377", "^ .|\\\\)(\\[\\]")) goto l4;

  l5:;	
  {  int yypos6= G->pos, yythunkpos6= G->thunkpos;  if (!yymatchClass(G, (const unsigned char *)"\377\377\377\377\376\274\377\377\377\377\377\307\377\377\377\357\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377\377", "^ .|\\\\)(\\[\\]")) goto l6;
  goto l5;
  l6:;	  G->pos= yypos6; G->thunkpos= yythunkpos6;
  }  yyText(G, G->begin, G->end);  if (!(YY_END)) goto l4;  yyDo(G, yy_1_raw_part, G->begin, G->end, "yy_1_raw_part");
  goto l3;
  l4:;	  G->pos= yypos3; G->thunkpos= yythunkpos3;  if (!yy_esc(G))  goto l7;
  if (!yymatchChar(G, '.')) goto l7;
  yyDo(G, yy_2_raw_part, G->begin, G->end, "yy_2_raw_part");
  goto l3;
  l7:;	  G->pos= yypos3; G->thunkpos= yythunkpos3;  if (!yy_esc(G))  goto l2;
  if (!yymatchChar(G, 't')) goto l2;
  yyDo(G, yy_3_raw_part, G->begin, G->end, "yy_3_raw_part");

  }
  l3:;	  yyprintf((stderr, "  ok   raw_part"));
  yyprintfGcontext;
  yyprintf((stderr, "\n"));

  return 1;
  l2:;	  G->pos= yypos0; G->thunkpos= yythunkpos0;  yyprintfv((stderr, "  fail %s", "raw_part"));
  yyprintfvGcontext;
  yyprintfv((stderr, "\n"));

  return 0;
}
YY_RULE(int) yy_raw(GREG *G)
{  int yypos0= G->pos, yythunkpos0= G->thunkpos;  yyDo(G, yyPush, 2, 0, "yyPush");
  yyprintfv((stderr, "%s\n", "raw"));
  if (!yy_raw_part(G))  goto l8;
  yyDo(G, yySet, -2, 0, "yySet");
  yyDo(G, yy_1_raw, G->begin, G->end, "yy_1_raw");

  l9:;	
  {  int yypos10= G->pos, yythunkpos10= G->thunkpos;  if (!yy_raw_part(G))  goto l10;
  yyDo(G, yySet, -1, 0, "yySet");
  yyDo(G, yy_2_raw, G->begin, G->end, "yy_2_raw");
  goto l9;
  l10:;	  G->pos= yypos10; G->thunkpos= yythunkpos10;
  }  yyDo(G, yy_3_raw, G->begin, G->end, "yy_3_raw");
  yyprintf((stderr, "  ok   raw"));
  yyprintfGcontext;
  yyprintf((stderr, "\n"));
  yyDo(G, yyPop, 2, 0, "yyPop");
  return 1;
  l8:;	  G->pos= yypos0; G->thunkpos= yythunkpos0;  yyprintfv((stderr, "  fail %s", "raw"));
  yyprintfvGcontext;
  yyprintfv((stderr, "\n"));

  return 0;
}
YY_RULE(int) yy_tail(GREG *G)
{  int yypos0= G->pos, yythunkpos0= G->thunkpos;  yyprintfv((stderr, "%s\n", "tail"));
  if (!yymatchString(G, "$$")) goto l11;
  yyDo(G, yy_1_tail, G->begin, G->end, "yy_1_tail");
  yyprintf((stderr, "  ok   tail"));
  yyprintfGcontext;
  yyprintf((stderr, "\n"));

  return 1;
  l11:;	  G->pos= yypos0; G->thunkpos= yythunkpos0;  yyprintfv((stderr, "  fail %s", "tail"));
  yyprintfvGcontext;
  yyprintfv((stderr, "\n"));

  return 0;
}
YY_RULE(int) yy_head(GREG *G)
{  int yypos0= G->pos, yythunkpos0= G->thunkpos;  yyprintfv((stderr, "%s\n", "head"));
  if (!yymatchString(G, "^^")) goto l12;
  yyDo(G, yy_1_head, G->begin, G->end, "yy_1_head");
  yyprintf((stderr, "  ok   head"));
  yyprintfGcontext;
  yyprintf((stderr, "\n"));

  return 1;
  l12:;	  G->pos= yypos0; G->thunkpos= yythunkpos0;  yyprintfv((stderr, "  fail %s", "head"));
  yyprintfvGcontext;
  yyprintfv((stderr, "\n"));

  return 0;
}
YY_RULE(int) yy_term(GREG *G)
{  int yypos0= G->pos, yythunkpos0= G->thunkpos;  yyDo(G, yyPush, 1, 0, "yyPush");
  yyprintfv((stderr, "%s\n", "term"));

  {  int yypos14= G->pos, yythunkpos14= G->thunkpos;  if (!yy_head(G))  goto l15;
  goto l14;
  l15:;	  G->pos= yypos14; G->thunkpos= yythunkpos14;  if (!yy_tail(G))  goto l16;
  goto l14;
  l16:;	  G->pos= yypos14; G->thunkpos= yythunkpos14;  if (!yy_raw(G))  goto l17;
  goto l14;
  l17:;	  G->pos= yypos14; G->thunkpos= yythunkpos14;  if (!yymatchChar(G, '(')) goto l18;
  if (!yy__(G))  goto l18;
  if (!yy_pattern(G))  goto l18;
  yyDo(G, yySet, -1, 0, "yySet");
  if (!yy__(G))  goto l18;
  if (!yymatchChar(G, ')')) goto l18;
  yyDo(G, yy_1_term, G->begin, G->end, "yy_1_term");
  goto l14;
  l18:;	  G->pos= yypos14; G->thunkpos= yythunkpos14;  if (!yymatchChar(G, '[')) goto l19;
  if (!yy__(G))  goto l19;
  if (!yy_pattern(G))  goto l19;
  yyDo(G, yySet, -1, 0, "yySet");
  if (!yy__(G))  goto l19;
  if (!yymatchChar(G, ']')) goto l19;
  yyDo(G, yy_2_term, G->begin, G->end, "yy_2_term");
  goto l14;
  l19:;	  G->pos= yypos14; G->thunkpos= yythunkpos14;  if (!yymatchChar(G, '.')) goto l13;
  yyDo(G, yy_3_term, G->begin, G->end, "yy_3_term");

  }
  l14:;	  yyprintf((stderr, "  ok   term"));
  yyprintfGcontext;
  yyprintf((stderr, "\n"));
  yyDo(G, yyPop, 1, 0, "yyPop");
  return 1;
  l13:;	  G->pos= yypos0; G->thunkpos= yythunkpos0;  yyprintfv((stderr, "  fail %s", "term"));
  yyprintfvGcontext;
  yyprintfv((stderr, "\n"));

  return 0;
}
YY_RULE(int) yy_terms(GREG *G)
{  int yypos0= G->pos, yythunkpos0= G->thunkpos;  yyDo(G, yyPush, 2, 0, "yyPush");
  yyprintfv((stderr, "%s\n", "terms"));
  if (!yy_term(G))  goto l20;
  yyDo(G, yySet, -2, 0, "yySet");
  yyDo(G, yy_1_terms, G->begin, G->end, "yy_1_terms");

  l21:;	
  {  int yypos22= G->pos, yythunkpos22= G->thunkpos;  if (!yy__(G))  goto l22;
  if (!yy_term(G))  goto l22;
  yyDo(G, yySet, -1, 0, "yySet");
  yyDo(G, yy_2_terms, G->begin, G->end, "yy_2_terms");
  goto l21;
  l22:;	  G->pos= yypos22; G->thunkpos= yythunkpos22;
  }  yyDo(G, yy_3_terms, G->begin, G->end, "yy_3_terms");
  yyprintf((stderr, "  ok   terms"));
  yyprintfGcontext;
  yyprintf((stderr, "\n"));
  yyDo(G, yyPop, 2, 0, "yyPop");
  return 1;
  l20:;	  G->pos= yypos0; G->thunkpos= yythunkpos0;  yyprintfv((stderr, "  fail %s", "terms"));
  yyprintfvGcontext;
  yyprintfv((stderr, "\n"));

  return 0;
}
YY_RULE(int) yy_end_of_file(GREG *G)
{  int yypos0= G->pos, yythunkpos0= G->thunkpos;  yyprintfv((stderr, "%s\n", "end_of_file"));

  {  int yypos24= G->pos, yythunkpos24= G->thunkpos;  if (!yymatchChar(G, '\0')) goto l24;
  goto l23;
  l24:;	  G->pos= yypos24; G->thunkpos= yythunkpos24;
  }  yyprintf((stderr, "  ok   end_of_file"));
  yyprintfGcontext;
  yyprintf((stderr, "\n"));

  return 1;
  l23:;	  G->pos= yypos0; G->thunkpos= yythunkpos0;  yyprintfv((stderr, "  fail %s", "end_of_file"));
  yyprintfvGcontext;
  yyprintfv((stderr, "\n"));

  return 0;
}
YY_RULE(int) yy_pattern(GREG *G)
{  int yypos0= G->pos, yythunkpos0= G->thunkpos;  yyDo(G, yyPush, 2, 0, "yyPush");
  yyprintfv((stderr, "%s\n", "pattern"));

  {  int yypos26= G->pos, yythunkpos26= G->thunkpos;  if (!yy_terms(G))  goto l27;
  yyDo(G, yySet, -2, 0, "yySet");
  if (!yy__(G))  goto l27;
  if (!yymatchChar(G, '|')) goto l27;
  if (!yy__(G))  goto l27;
  if (!yy_pattern(G))  goto l27;
  yyDo(G, yySet, -1, 0, "yySet");
  yyDo(G, yy_1_pattern, G->begin, G->end, "yy_1_pattern");
  goto l26;
  l27:;	  G->pos= yypos26; G->thunkpos= yythunkpos26;  if (!yy_terms(G))  goto l25;

  }
  l26:;	  yyprintf((stderr, "  ok   pattern"));
  yyprintfGcontext;
  yyprintf((stderr, "\n"));
  yyDo(G, yyPop, 2, 0, "yyPop");
  return 1;
  l25:;	  G->pos= yypos0; G->thunkpos= yythunkpos0;  yyprintfv((stderr, "  fail %s", "pattern"));
  yyprintfvGcontext;
  yyprintfv((stderr, "\n"));

  return 0;
}
YY_RULE(int) yy__(GREG *G)
{  yyprintfv((stderr, "%s\n", "_"));

  l29:;	
  {  int yypos30= G->pos, yythunkpos30= G->thunkpos;  if (!yymatchChar(G, ' ')) goto l30;
  goto l29;
  l30:;	  G->pos= yypos30; G->thunkpos= yythunkpos30;
  }  yyprintf((stderr, "  ok   _"));
  yyprintfGcontext;
  yyprintf((stderr, "\n"));

  return 1;
}
YY_RULE(int) yy_rockre(GREG *G)
{  int yypos0= G->pos, yythunkpos0= G->thunkpos;  yyDo(G, yyPush, 1, 0, "yyPush");
  yyprintfv((stderr, "%s\n", "rockre"));
  if (!yy__(G))  goto l31;
  if (!yy_pattern(G))  goto l31;
  yyDo(G, yySet, -1, 0, "yySet");
  if (!yy__(G))  goto l31;
  if (!yy_end_of_file(G))  goto l31;
  yyDo(G, yy_1_rockre, G->begin, G->end, "yy_1_rockre");
  yyprintf((stderr, "  ok   rockre"));
  yyprintfGcontext;
  yyprintf((stderr, "\n"));
  yyDo(G, yyPop, 1, 0, "yyPop");
  return 1;
  l31:;	  G->pos= yypos0; G->thunkpos= yythunkpos0;  yyprintfv((stderr, "  fail %s", "rockre"));
  yyprintfvGcontext;
  yyprintfv((stderr, "\n"));

  return 0;
}

#ifndef YY_PART

typedef int (*yyrule)(GREG *G);

YY_PARSE(int) YY_NAME(parse_from)(GREG *G, yyrule yystart)
{
  int yyok;
  if (!G->buflen)
    {
      G->buflen= YY_BUFFER_START_SIZE;
      G->buf= (char*)YY_ALLOC(G->buflen, G->data);
      G->textlen= YY_BUFFER_START_SIZE;
      G->text= (char*)YY_ALLOC(G->textlen, G->data);
      G->thunkslen= YY_STACK_SIZE;
      G->thunks= (yythunk*)YY_ALLOC(sizeof(yythunk) * G->thunkslen, G->data);
      G->valslen= YY_STACK_SIZE;
      G->vals= (YYSTYPE*)YY_ALLOC(sizeof(YYSTYPE) * G->valslen, G->data);
      G->begin= G->end= G->pos= G->limit= G->thunkpos= 0;
    }
  G->pos = 0;
  G->begin= G->end= G->pos;
  G->thunkpos= 0;
  G->val= G->vals;
  yyok= yystart(G);
  if (yyok) yyDone(G);
  yyCommit(G);
  return yyok;
  (void)yyrefill;
  (void)yymatchDot;
  (void)yymatchChar;
  (void)yymatchString;
  (void)yymatchClass;
  (void)yyDo;
  (void)yyText;
  (void)yyDone;
  (void)yyCommit;
  (void)yyAccept;
  (void)yyPush;
  (void)yyPop;
  (void)yySet;
}

YY_PARSE(int) YY_NAME(parse)(GREG *G)
{
  return YY_NAME(parse_from)(G, yy_rockre);
}

YY_PARSE(void) YY_NAME(init)(GREG *G)
{
    memset(G, 0, sizeof(GREG));
}
YY_PARSE(void) YY_NAME(deinit)(GREG *G)
{
    if (G->buf) YY_FREE(G->buf);
    if (G->text) YY_FREE(G->text);
    if (G->thunks) YY_FREE(G->thunks);
    if (G->vals) YY_FREE((void*)G->vals);
}
YY_PARSE(GREG *) YY_NAME(parse_new)(YY_XTYPE data)
{
  GREG *G = (GREG *)YY_CALLOC(1, sizeof(GREG), G->data);
  G->data = data;
  return G;
}

YY_PARSE(void) YY_NAME(parse_free)(GREG *G)
{
  YY_NAME(deinit)(G);
  YY_FREE(G);
}

#endif


RockRE::Node RockRE::parse(std::string str)
{
    RockRE::Node root;
    GREG g;
    YY_NAME(init)(&g);
    std::unique_ptr<RockRE::ParserInput> input(new RockRE::ParserInput(str));
    g.data.input(input.get());

    if (!YY_NAME(parse)(&g)) {
        fprintf(stderr, "Syntax error\n");
        goto FINALIZE;
    }
    if (g.limit != g.pos) {
        fprintf(stderr, "Syntax error %d\n", g.limit);
        goto FINALIZE;
    }
    root = g.data.root();

FINALIZE:
    YY_NAME(deinit)(&g);
    return root;
}


