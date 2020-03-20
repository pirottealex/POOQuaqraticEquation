// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// STL
#include <cassert>
#include <iostream>
#include <memory> // pour utiliser les pointeurs intelligents
#include <Eq2degComp.hpp>

using namespace std;

int main(){
    //everything as to be done
    double a, b, c;
    
    // add code to retrieve the coeffcients from user input
    
    printf("Hey ! Choose some coefficient. a : ");
    scanf("%lf",&a);
    printf("For the b : ");
    scanf("%lf",&b);
    printf("Finally for the c : ");
    scanf("%lf",&c);
    

  try { // Eq2deg can throw exceptions so we need to catch them
      
    //Pointeur intelligent
    unique_ptr<Eq2degComp> myEq(new Eq2degComp(a,b,c));
    assert (myEq != nullptr); // Just make sure everything OK
    
    // Add code to solve the equation and display the result
    myEq->computeDelta();
    myEq->computeRoots();
    cout << *myEq << endl;

    // Pas besoin de libérer la mémoire su run pointeur intélligent, c'ets fait automatiquement

  // utilisation de cette commande pour vérifier les fuites mémoire :
  // valgrind --tool=memcheck --leak-check=summary --leak-resolution=high --show-reachable=yes ./solver

  } catch (const std::exception& ex) {
    std::cerr << "Exception raised: " << ex.what() << std::endl;
  }
  // Improve exception handling by separating different exception type
  return 0;

}