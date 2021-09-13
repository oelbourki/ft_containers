#pragma once

namespace ft
{
  // template <class ForwardIterator>
  // typedef typename std::iterator_traits<ForwardIterator>::difference_type difference_type;
    template <class InputIterator>
  void distance(InputIterator first,InputIterator last,ptrdiff_t& n)
  {
    if (first == last)
      return ;
    for ( n = 0; first != last; n++)
    {
      first++;
    }
    return ;
  }
 template <class InputIterator>
  void advance (InputIterator& it, ptrdiff_t n)
  {
    while (n > 0)
    {
      ++it;
      n--;
    }
    
  }
template <class ForwardIterator, class T>
  ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
    // std::cout << "i am her"<< std::endl;
//   ForwardIterator it;
//  typename std::iterator_traits<ForwardIterator>::difference_type count, step;
//   count = distance(first,last);
//   while (count>0)
//   {
//     it = first; step=count/2; 
//     // std::cout << it->first << std::endl;
//     advance (it,step);
//     // std::cout << it->first << std::endl;
//     // std::cout <<"low>> "<<val.first << " " << it->first << std::endl;
//     // std::cout << "comp>> " << (it->first<val.first) << std::endl;
//     if (it->first<val.first) {   
//       first=++it;
//       count-=step+1;
//     }
//     else count=step;
//   }
ForwardIterator tmp;
//   std::cout << "{} "<<first->first << std::endl;
tmp = first;
while (first != last)
{
    if (first->first < val.first)
        first++;
    else if (first->first == val.first)
        break;
    else
    {
        first++;
    }
}

  return first;
}
template <class ForwardIterator, class T,class Compare>
  ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val,Compare comp)
{
    // std::cout << "good" << std::endl;
  ForwardIterator it;
 typename std::iterator_traits<ForwardIterator>::difference_type count, step;
  count = distance(first,last);
  while (count>0)
  {
    it = first; step=count/2; advance (it,step);
    // std::cout <<"low>> "<<val.first << " " << it->first << std::endl;
    // std::cout << "comp>> " <<comp(val.first,(it->first)) << std::endl;
    if (comp((it->first),(val.first))) {                 // or: if (comp(it->first,val.first)), for version (2)
      first=++it;
      count-=step+1;
    }
    else count=step;
  }
  return first;
}
template <class ForwardIterator, class T>
  ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val)
{
    // std::cout << "fg" << std::endl;
  ForwardIterator it;
  typename std::iterator_traits<ForwardIterator>::difference_type count, step;
  count = distance(first,last);
  while (count>0)
  {
    it = first; step=count/2; advance (it,step);
    if (!(val<*it))                 // or: if (!comp(val,*it)), for version (2)
      { first=++it; count-=step+1;  }
    else count=step;
  }
  if (first == last)
    return last;
  return ++first;
}
// template <class ForwardIterator, class T>
//   ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val)
// {
//     std::cout << "upperbbb" << std::endl;
//   ForwardIterator it;
//   typename std::iterator_traits<ForwardIterator>::difference_type count, step;
//   count = std::distance(first,last);
//   while (count>0)
//   {
//     it = first; step=count/2; std::advance (it,step);
//     if (!(val.first< it->first))                 // or: if (!comp(val.first,it->first)), for version (2)
//       { first=++it; count-=step+1;  }
//     else count=step;
//   }


// //   ForwardIterator tmp;
// // //   std::cout << "{} "<<first->first << std::endl;
// // tmp = first;
// // while (first != last)
// // {

// //     if (first->first == val.first)
// //         break;
// //     else if (!(val.first < first->first) )
// //         first++;
// // }
//   return first;
// }
template <class ForwardIterator, class T,class Compare>
  ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, const T& val,Compare cmp)
{
    // std::cout << "upperghgf"<< std::endl;
  ForwardIterator it;
  typename std::iterator_traits<ForwardIterator>::difference_type count, step;
  count = std::distance(first,last);
  while (count>0)
  {
    it = first; step=count/2; std::advance (it,step);
    if (!comp(val.first,it->first))                // or: if (!comp(val.first,it->first)), for version (2)
      { first=++it; count-=step+1;  }
    else count=step;
  }
  return first;
}
}