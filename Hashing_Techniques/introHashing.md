//Hashing function is used to map the keys to a particular index using hash function 
// For e.g. Let us take a hash function H(x) = x. Here x is the value in H(x), and the result gives us the index which is the value itself.


// Loading factor(lambda) = (no of keys)/(size of the table)
//Loading factor should always be less than or equal to 0.5.

// Analysis is always based on the loading factor.


// But it has a large space complexity, which can be solved using modulus function.
// For e.g. H(x) = x%10

//This method also creates a problem of collisio i.e. when two key values map to the same index.
//For e.g. H(5) = 5 (5%10 = 5) and H(25) = 5 (25%10 = 5)