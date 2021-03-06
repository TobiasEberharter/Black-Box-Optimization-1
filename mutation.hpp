/* mutation.hpp
*
* This namespace will have all of the different implementations of the population
* mutation of the evolutionary algorithm.
*/
#ifndef BBO_MUTATION_HPP
#define BBO_MUTATION_HPP

#include "API/KusiakLayoutEvaluator.h"

#include "structures.hpp"

namespace mutation{
   /*
    * mutation::none
    *
    * null function in case that we want to try not using any mutation
    */
   void none(individual&, KusiakLayoutEvaluator&) {}
   
   /*
    * mutation::creep
    *
    * applies creep (incremental mutation) to one individual
    * creep steps are sampled from a cauchy distribution
    * the function tests for layout boundaries and re-enforces them
    *
    * parameters:
    * range - the distribution will be (-range, range)
    * width - the layout width
    * height - the layout height
    * individual - the individual to mutate
    * kle - the evaluator
    */
   // TODO: replace width/height with WindScenario&
   void creep(double range, double width, double height,
              individual& indiv, KusiakLayoutEvaluator& kle);
   
   /*
    * mutation::random_reset
    *
    * applies a mutation which simply resets a random number of coordinates
    * each x and y coordinate has a chance to be reset independently
    * reset coordinates are drawn uniformly from 0 to the layout boundaries
    *
    * parameters:
    * chance - probability that a coordinate is reset
    * width - the layout width
    * height - the layout height
    * individual - the individual to mutate
    */
   // TODO: replace width/height with WindScenario&
   void random_reset(float chance, double width, double height,
                     individual& indiv, KusiakLayoutEvaluator& kle);
}

#endif
