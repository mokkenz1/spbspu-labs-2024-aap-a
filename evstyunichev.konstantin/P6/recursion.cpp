#include "recursion.hpp"
#include <iostream>
const char * evstyunichev::is_factor_correct(const char *p, int prev)
{
  if (p == nullptr) return nullptr;
  int cur = 4;
  if (evstyunichev::is_letter(*p))
  {
    cur = (prev == 3);
  }
  if (evstyunichev::is_digit(*p))
  {
    cur = 2 & prev;
  }
  if (cur & 4)
  {
    return p;
  }
  if (cur)
  {
    return evstyunichev::is_factor_correct(++p, cur);
  }
  return nullptr;
}

const char * evstyunichev::is_term_correct(const char *p, int prev)
{
  if (p == nullptr)
  {
    return nullptr;
  }
  if (is_basic_symbol(*p))
  {
    return is_term_correct(is_factor_correct(p), 0);
  }
  if (*p == '(')
  {
    p++;
    p = is_expression_correct(p, 1, 1);
    if (!p)
    {
      return p;
    }
    if (*p != ')')
    {
      return nullptr;
    }
    p++;
    return is_term_correct(p, 0);
  }
  if (prev)
  {
    return nullptr;
  }
  if (*p == '*')
  {
    return is_term_correct(++p);
  }
  return p;
}

const char * evstyunichev::is_expression_correct(const char *p, int prev, bool OpenFlag)
{
  if (p == nullptr)
  {
    return nullptr;
  }
  if (is_basic_symbol(*p))
  {
    return is_expression_correct(is_term_correct(p), 0, OpenFlag);
  }
  if (*p == '(')
  {
    return is_term_correct(p);
  }
  if (prev)
  {
    return nullptr;
  }
  if (is_sign(*p))
  {
    return is_expression_correct(++p, 1, OpenFlag);
  }
  if (*p == 0)
  {
    return p;
  }
  if (OpenFlag && (*p == ')'))
  {
    return p;
  }
  return nullptr;
}

bool evstyunichev::is_letter(char c, char cur)
{
  if (cur == 'z' + 1)
  {
    return 0;
  }
  if (cur == c)
  {
    return 1;
  }
  if (cur == 'f')
  {
    is_letter(c, 'x');
  }
  return is_letter(c, cur + 1);
}

bool evstyunichev::is_digit(char c, char cur)
{
  if (cur == '9' + 1)
  {
    return 0;
  }
  if (cur == c)
  {
    return 1;
  }
  return is_digit(c, cur + 1);
}

bool evstyunichev::is_basic_symbol(char c)
{
  return (evstyunichev::is_digit(c) || evstyunichev::is_letter(c));
}

bool evstyunichev::is_sign(char c)
{
  return ((c == '+') || (c == '-'));
}
