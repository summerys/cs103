CSCI 103 Six Degrees of Kevin Bacon

Name: Summer Seo 

Email Address: summeryseo@usc.edu

: CP on Thursday, Friday
: Discussion with peer. 

================================ Remarks ====================================
: about 5 days. but I did little bit each days. 

: I had a problem with group function. 
  I tried to fix it for 3 days, going over written algorithms 
  but I was not abot to spot a problem for a long time
  later on I realized I had pretty had algorithm from the beginning.
  I had to come up with new algorithm and finished in an hour 
  for a problem I had to figure out for 3 days.
  I learned more about how to think out of the box. 
  It was overall a huge achievement for me. 

: For my shortest-path, it did not pass the tests on the bits website 
  because what I did was to print out backward 
  in social_network.cpp fuction.
  I pushed back numbers into vector from the end # 
  to start # tracking predecessor.

  when I added:

  for(int i=return_shortest_path.size()-1; i>=0; i--)
  {
    backwards.push_back(return_shortest_path[i]);
  }
  return_shortest_path.clear();

  for(int i=0; i<backwards.size(); i++){
    return_shortest_path.push_back(backwards[i]);
  }

  this part to print it backwards,
  my gorup function did not work. 
  I marked this inside of network.cpp. 


