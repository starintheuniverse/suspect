# suspect
Minimal-effort registering global references to static local variables for debugging.

Provides something similar to defining global variables and using them in and out of a function.
But, using global variables directly means that any change needs code updates in at least three places.
With this small library, static variables in a function can be used instead.
This is more conveninent because the declaration of the variable lives next to its usage.

Furthermore, the registry keeps a list of all (specially defined) variables,
enabling an automatic report to be generated without manually printing each one.
