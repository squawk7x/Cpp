//############################################################################
/*
 * Code Reuse: Inheritance Vs. Composition
 */
//############################################################################

// class BaseDog {
//     ...... // common activities
// };

// class BullDog : public BaseDog {
//     ... // Call the common activities to perform more tasks.
// };

// class ShepherdDog : public BaseDog {
//     ... // Call the common activities to perform more tasks.
// };

// // Code Reuse with composition

// class ActivityManager {
//     ... // common activities
// };

// class Dog {
//     ...
// };

// class BullDog : public Dog {
//     ActivityManager* pActMngr;
//     ... // Call the common activities through pActMngr
// };

// class ShepherdDog : public Dog {
//     ActivityManager* pActMngr;
//     ... // Call the common activities through pActMngr
// };

// /*
//  * Code reuse: composition is better than inheritance
//  *
//  * 1. Less code coupling between reused code and reuser of the code
//  *    a. Child class automatically inherits ALL parent class's public members.
//  *    b. Child class can access parent's protected members.
//  *       - Inheritance breaks encapsulation
//  */

// /*
//  * 2. Dynamic binding
//  *    a. Inheritance is bound at compile time
//  *    b. Composition can be bound either at compile time or at run time.
//  */

// class OutdoorActivityManager : public ActivityManager {
//     ...
// }

// class IndoorActivityManager : public ActivityManager {
//     ...
// }

/*
 * 3. Flexible code construct
 *
 *    Dog             ActivityManager
 *
 *    BullDog         OutdoorActivityManager
 *    ShepherdDog     IndoorActivityManager
 *    ...             ...
 */

/*
 * RESERVED
 */

/*
 * "Never use inheritance for code reuse!"
 *
 * "Inherit interfaces only; never inherit implementation!"
 *
 * "All base classes should be Pure Abstract Classes!"
 */

// Composition Example: Inherit only from pure abstract class:
// class ActivityManager {
//     void eatBiscuit() {
//         ...
//     }
// };

// class Dog {
//     ... virtual void eatBiscuit() = 0;
// };

// class BullDog : public Dog {
//     ActivityManager* pActMngr;
//     ... void eatBiscuit() {
//         pActMngr->eatBiscuit();
//     }
// };

// class ShepherdDog : public Dog {
//     ActivityManager* pActMngr;
//     ... void eatBiscuit() {
//         pActMngr->eatBiscuit();
//     }
// };

// // Inheritance Example:
// class Dog {
//     ... void eatBiscuit() {
//         ...
//     }
// };

// class BullDog : public Dog {
//     ...
// };

// class ShepherdDog : public Dog {
//     ...
// };

// virtual function is another benefit of implementation inheritance.

/*
 * 1. Minimize the implementation in base classes. Base classes should be thin.
 * 2. Minimize the level of hierarchies in implementation inheritance.
 */

/*
 * "Inheritance is evil"  ???
 *
 * "Inheritance is often useful, but more often overused (abused)."
 *
 * Guidelines for Implementation Inheritance:
 * 1. Do not use inheritance for code reuse, use composition.
 * 2. Minimize the implementation in base classes. Base classes should be thin.
 * 3. Minimize the level of hierarchies in implementation inheritance.
 */
