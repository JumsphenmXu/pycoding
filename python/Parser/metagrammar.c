
#include "pgenheaders.h"
#include "metagrammar.h"
#include "grammar.h"
#include "pgen.h"

/**
 *                     ENDMARKER
 *     +-------> s0 +----------------> s1
 *     |         | ^                    |
 *     |         |  \                   |
 *     +---------+   \------------------+
 *     RULE/NEWLINE        EMPTY
 *
 *
 *     MSTART -> (RULE|NEWLINE)* ENDMARKER
 *
 */


static arc arcs_0_0[3] = {
    {2, 0},
    {3, 0},
    {4, 1},
};
static arc arcs_0_1[1] = {
    {0, 1},
};
static state states_0[2] = {
    {3, arcs_0_0},
    {1, arcs_0_1},
};


/**
 *            NAME           COLON          RHS
 *     s0 -----------> s1 ----------> s2 ----------> s3
 *                                                   |
 *                                                   |
 *                       +----------- s4 <-----------+
 *                       |             ^     NEWLINE
 *                       |             |
 *                       +-------------+
 *                            EMPTY
 *
 *     RULE -> NAME : RHS NEWLINE
 *
 */
static arc arcs_1_0[1] = {
    {5, 1},
};
static arc arcs_1_1[1] = {
    {6, 2},
};
static arc arcs_1_2[1] = {
    {7, 3},
};
static arc arcs_1_3[1] = {
    {3, 4},
};
static arc arcs_1_4[1] = {
    {0, 4},
};
static state states_1[5] = {
    {1, arcs_1_0},
    {1, arcs_1_1},
    {1, arcs_1_2},
    {1, arcs_1_3},
    {1, arcs_1_4},
};

/**
 *               ALT
 *     s0 +----------------> s1 ------------+
 *     ^                    |  ^            |
 *      \                   |   \           |
 *       \------------------+    +----------+
 *                VBAR                EMPTY
 *
 *
 *     RULE -> ALT (| ALT)*
 *
 */
static arc arcs_2_0[1] = {
    {8, 1},
};
static arc arcs_2_1[2] = {
    {9, 0},
    {0, 1},
};
static state states_2[2] = {
    {1, arcs_2_0},
    {2, arcs_2_1},
};


/**
 *               ITEM
 *     s0 +-----------> s1 ------------+
 *                        ^            |
 *                         \           |
 *                          +----------+
 *                            ITEM/EMPTY
 *
 *
 *     ALT -> ITEM+
 *
 */
static arc arcs_3_0[1] = {
    {10, 1},
};
static arc arcs_3_1[2] = {
    {10, 1},
    {0, 1},
};
static state states_3[2] = {
    {1, arcs_3_0},
    {2, arcs_3_1},
};


/**
 *
 *            LSQB            RHS          RSQB
 *     s0 -----------> s1 ----------> s3 ----------> s4 ----------+
 *     |                                              ^           |
 *     |                                              | \         |
 *     +-------------> s2 ----------------------------+  +--------+
 *            ATOM     | ^        STAR/PLUS                 EMPTY
 *                     |   \
 *                     |    \
 *                     +-----+
 *                       EMPTY
 *
 *     ITEM -> [RHS] | ATOM[*|+]
 *
 */
static arc arcs_4_0[2] = {
    {11, 1},
    {13, 2},
};
static arc arcs_4_1[1] = {
    {7, 3},
};
static arc arcs_4_2[3] = {
    {14, 4},
    {15, 4},
    {0, 2},
};
static arc arcs_4_3[1] = {
    {12, 4},
};
static arc arcs_4_4[1] = {
    {0, 4},
};
static state states_4[5] = {
    {2, arcs_4_0},
    {1, arcs_4_1},
    {3, arcs_4_2},
    {1, arcs_4_3},
    {1, arcs_4_4},
};

/**
 *
 *            LPAR            RHS
 *     s0 -----------> s2 ----------> s3
 *     |                              |
 *     |                              | RPAR
 *     +-------------> s1 <-----------+
 *       NAME/STRING   | ^
 *                     |  \
 *                     +---+
 *                     EMPTY
 *
 *
 *     ATOM -> NAME | STRING | (RHS)
 *
 */
static arc arcs_5_0[3] = {
    {5, 1},
    {16, 1},
    {17, 2},
};
static arc arcs_5_1[1] = {
    {0, 1},
};
static arc arcs_5_2[1] = {
    {7, 3},
};
static arc arcs_5_3[1] = {
    {18, 1},
};
static state states_5[4] = {
    {3, arcs_5_0},
    {1, arcs_5_1},
    {1, arcs_5_2},
    {1, arcs_5_3},
};
static dfa dfas[6] = {
    {256, "MSTART", 0, 2, states_0,
     "\070\000\000"},
    {257, "RULE", 0, 5, states_1,
     "\040\000\000"},
    {258, "RHS", 0, 2, states_2,
     "\040\010\003"},
    {259, "ALT", 0, 2, states_3,
     "\040\010\003"},
    {260, "ITEM", 0, 5, states_4,
     "\040\010\003"},
    {261, "ATOM", 0, 4, states_5,
     "\040\000\003"},
};
static label labels[19] = {
    {0, "EMPTY"},         // 0, EMPTY
    {256, 0},             // 1, MSTART
    {257, 0},             // 2, RULE
    {4, 0},               // 3, NEWLINE
    {0, 0},               // 4, ENDMARKER
    {1, 0},               // 5, NAME
    {11, 0},              // 6, COLON
    {258, 0},             // 7, RHS
    {259, 0},             // 8, ALT
    {18, 0},              // 9, VBAR
    {260, 0},             // 10, ITEM
    {9, 0},               // 11, LSQB
    {10, 0},              // 12, RSQB
    {261, 0},             // 13, ITEM
    {16, 0},              // 14, STAR
    {14, 0},              // 15, PLUS
    {3, 0},               // 16, STRING
    {7, 0},               // 17, LPAR
    {8, 0},               // 18, RPAR
};
static grammar _PyParser_Grammar = {
    6,
    dfas,
    {19, labels},
    256
};

grammar *
meta_grammar(void)
{
    return &_PyParser_Grammar;
}

grammar *
Py_meta_grammar(void)
{
  return meta_grammar();
}
