1.)All paths/All choices

2.)Controlled Recursion
If house in SouthWest then we dont need to go east or north...

3.)Number of choices.(generally more than one or two).Choices might be a variable.

4.)Size of contraints- n is generally a single digit. VERY IMPORTANT SIGNAL TO IDNETIFY.

void BT() //generally void but not necessary
{
  //some base condn...This can also be some separate solve function
  
  for()  //more choices so generally a for loop
  {
    if(isValid)
    BT()
  }
  
  
}
