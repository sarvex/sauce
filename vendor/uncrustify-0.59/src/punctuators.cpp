/**
 * @file punctuators.cpp
 * Manages the table of punctutators.
 *
 * @author  Ben Gardner
 * @license GPL v2+
 */
#include "uncrustify_types.h"
#include <cstring>


/**
 *
 *   The file "punctuators.h" was generated by punc.py from this file.
 *   If you change one of the below symbol tables, re-run punc.py.
 *   $ python scripts/punc.py > src/punctuators.h
 *
 */


/* 4-char symbols */
static const chunk_tag_t symbols4[] =
{
   { "!<>=", CT_COMPARE, LANG_D                         },
   { ">>>=", CT_ASSIGN,  LANG_D | LANG_JAVA | LANG_PAWN },
};

/* 3-char symbols */
static const chunk_tag_t symbols3[] =
{
   { "!<=", CT_COMPARE,  LANG_D                                 },
   { "!<>", CT_COMPARE,  LANG_D                                 },
   { "!==", CT_COMPARE,  LANG_D                                 },
   { "!>=", CT_COMPARE,  LANG_D                                 },
   { "->*", CT_MEMBER,   LANG_C | LANG_CPP | LANG_D             },
   { "...", CT_ELLIPSIS, LANG_C | LANG_CPP | LANG_D | LANG_PAWN },
   { "<<=", CT_ASSIGN,   LANG_ALL                               },
   { "<>=", CT_COMPARE,  LANG_D                                 },
   { "===", CT_COMPARE,  LANG_D                                 },
   { ">>=", CT_ASSIGN,   LANG_ALL                               },
   { ">>>", CT_ARITH,    LANG_D | LANG_JAVA | LANG_PAWN         },
};

/* 2-char symbols */
static const chunk_tag_t symbols2[] =
{
   { "!<", CT_COMPARE,      LANG_D                                         },
   { "!=", CT_COMPARE,      LANG_ALL                                       },
   { "!>", CT_COMPARE,      LANG_D                                         },
   { "!~", CT_COMPARE,      LANG_D                                         },
   { "##", CT_PP,           LANG_C | LANG_CPP | LANG_OC                    },
   { "#@", CT_POUND,        LANG_C | LANG_CPP | LANG_OC                    }, /* MS extension */
   { "%=", CT_ASSIGN,       LANG_ALL                                       },
   { "&&", CT_BOOL,         LANG_ALL                                       },
   { "&=", CT_ASSIGN,       LANG_ALL                                       },
   { "*=", CT_ASSIGN,       LANG_ALL                                       },
   { "++", CT_INCDEC_AFTER, LANG_ALL                                       },
   { "+=", CT_ASSIGN,       LANG_ALL                                       },
   { "--", CT_INCDEC_AFTER, LANG_ALL                                       },
   { "-=", CT_ASSIGN,       LANG_ALL                                       },
   { "->", CT_MEMBER,       LANG_C | LANG_CPP | LANG_CS | LANG_OC | LANG_D },
   { ".*", CT_MEMBER,       LANG_C | LANG_CPP | LANG_D                     },
   { "..", CT_RANGE,        LANG_D                                         },
   { "/=", CT_ASSIGN,       LANG_ALL                                       },
   { "::", CT_DC_MEMBER,    LANG_C | LANG_CPP | LANG_CS | LANG_D           },
   { "<<", CT_ARITH,        LANG_ALL                                       },
   { "<=", CT_COMPARE,      LANG_ALL                                       },
   { "<>", CT_COMPARE,      LANG_D                                         },
   { "==", CT_COMPARE,      LANG_ALL                                       },
   { ">=", CT_COMPARE,      LANG_ALL                                       },
   { ">>", CT_ARITH,        LANG_ALL & ~LANG_CS                            },
   { "[]", CT_TSQUARE,      LANG_ALL                                       },
   { "^=", CT_ASSIGN,       LANG_ALL                                       },
   { "|=", CT_ASSIGN,       LANG_ALL                                       },
   { "||", CT_BOOL,         LANG_ALL                                       },
   { "~=", CT_COMPARE,      LANG_D                                         },
   { "~~", CT_COMPARE,      LANG_D                                         },
   { "=>", CT_LAMBDA,       LANG_VALA | LANG_CS                            },
   { "??", CT_COMPARE,      LANG_CS                                        },
};

/* 1-char symbols */
static const chunk_tag_t symbols1[] =
{
   { "!", CT_NOT,          LANG_ALL                                                   },
   { "#", CT_POUND,        LANG_C | LANG_CPP | LANG_CS | LANG_D | LANG_OC | LANG_PAWN },
   { "$", CT_COMPARE,      LANG_D                                                     },
   { "%", CT_ARITH,        LANG_ALL                                                   },
   { "&", CT_AMP,          LANG_ALL                                                   },
   { "(", CT_PAREN_OPEN,   LANG_ALL                                                   },
   { ")", CT_PAREN_CLOSE,  LANG_ALL                                                   },
   { "*", CT_STAR,         LANG_ALL                                                   },
   { "+", CT_PLUS,         LANG_ALL                                                   },
   { ",", CT_COMMA,        LANG_ALL                                                   },
   { "-", CT_MINUS,        LANG_ALL                                                   },
   { ".", CT_DOT,          LANG_ALL                                                   },
   { "/", CT_ARITH,        LANG_ALL                                                   },
   { ":", CT_COLON,        LANG_ALL                                                   },
   { ";", CT_SEMICOLON,    LANG_ALL                                                   },
   { "<", CT_ANGLE_OPEN,   LANG_ALL                                                   },
   { "=", CT_ASSIGN,       LANG_ALL                                                   },
   { ">", CT_ANGLE_CLOSE,  LANG_ALL                                                   },
   { "?", CT_QUESTION,     LANG_ALL                                                   },
   { "[", CT_SQUARE_OPEN,  LANG_ALL                                                   },
   { "]", CT_SQUARE_CLOSE, LANG_ALL                                                   },
   { "^", CT_ARITH,        LANG_ALL                                                   },
   { "{", CT_BRACE_OPEN,   LANG_ALL                                                   },
   { "|", CT_ARITH,        LANG_ALL                                                   },
   { "}", CT_BRACE_CLOSE,  LANG_ALL                                                   },
   { "~", CT_INV,          LANG_ALL                                                   },
};

#include "punctuators.h"

const chunk_tag_t *find_punctuator(const char *str, int lang_flags)
{
   const chunk_tag_t    *p_match = NULL;
   const lookup_entry_t *p_tab   = punc_table;

   int ch_idx = 0;

   /*REVISIT: it might be faster to do a bsearch() on the first char.
    *         the rest of the group have at most 5 entries, so it wouldn't help
    */

   while (ch_idx < 4)
   {
      if (p_tab->ch == str[ch_idx])
      {
         /* Match */
         if ((p_tab->tag != NULL) &&
             ((p_tab->tag->lang_flags & lang_flags) != 0))
         {
            p_match = p_tab->tag;
         }
         if (p_tab->next_idx == 0)
         {
            /* This is the end of the chain */
            break;
         }
         p_tab = &punc_table[p_tab->next_idx];
         ch_idx++;
      }
      else if (p_tab->left_in_group == 0)
      {
         /* The last entry in this group didn't match */
         break;
      }
      else
      {
         p_tab++;
      }
   }
   return(p_match);
}
