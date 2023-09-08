class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.size();

        if(n<8) //It has at least 8 characters.
            return false;
        
        bool containLower=false, containUpper=false, containDigit=false, containSymbol=false;
        string symbol = "!@#$%^&*()-+";
        
        for(int i=1; i<n; i++) {
            if(password[i-1] == password[i]) //2 of the same character in adjacent positions
                return false;

            if( isdigit(password[i]) )
                containDigit = true;
            else if( islower(password[i]) )
                containLower = true;
            else if( isupper(password[i]) )
                containUpper = true;    
            else if( symbol.find(password[i]) != string::npos )
                containSymbol = true; 


            // if( containLower && containUpper && containDigit && containSymbol )
            //     return true;
        }

        if( isdigit(password[0]) )
            containDigit = true;
        else if( islower(password[0]) )
            containLower = true;
        else if( isupper(password[0]) )
            containUpper = true;    
        else if( symbol.find(password[0]) != string::npos )
                containSymbol = true; 

        // cout<<"\nDigit "<<containDigit;
        // cout<<"\nLower "<<containLower;
        // cout<<"\nUpper "<<containUpper;
        // cout<<"\nSymbol "<<containSymbol;


        if( containLower && containUpper && containDigit && containSymbol )
            return true;
        else
            return false;
    }
};