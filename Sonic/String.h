#pragma once

// Muhammad Ammar, 24I-0682, Assignment # 2

#include <iostream>
using namespace std;

class String {
private:
    char* Array;

public:

    String() {
        Array = new char[1];
        Array[0] = '\0';
    }

    String(const char* Input) {
        int Size;

        for (Size = 0; Input[Size] != '\0'; Size++) {}

        Array = new char[Size + 1]; // Accounting For Null
        Array[Size] = '\0';

        for (int i = 0; i < Size; i++) {
            Array[i] = Input[i];
        }
    }

    String(const String& Input) {
        int Size;

        for (Size = 0; Input.Array[Size] != '\0'; Size++) {}

        Array = new char[Size + 1]; // Accounting For Null
        Array[Size] = '\0';

        for (int i = 0; i < Size; i++) {
            Array[i] = Input.Array[i];
        }
    }

    String operator+(const String& Add) {
        String Copy(*this);

        int Size = this->len() + Add.len();

        delete[] Copy.Array;
        Copy.Array = nullptr;

        Copy.Array = new char[Size + 1]; // Accounting For Null
        Copy.Array[Size] = '\0';

        int Index;

        for (Index = 0; Array[Index] != '\0'; Index++) {
            Copy.Array[Index] = Array[Index];
        }

        for (int i = 0; Add.Array[i] != '\0'; i++) {
            Copy.Array[Index] = Add.Array[i];
            Index++;
        }

        return Copy;
    }

    String operator+(const char* Add) {
        String Copy(*this);

        int Size;
        for (Size = 0; Add[Size] != '\0'; Size++) {}

        Size += this->len();

        delete[] Copy.Array;
        Copy.Array = nullptr;

        Copy.Array = new char[Size + 1]; // Accounting For Null
        Copy.Array[Size] = '\0';

        int Index;

        for (Index = 0; Array[Index] != '\0'; Index++) {
            Copy.Array[Index] = Array[Index];
        }

        for (int i = 0; Add[i] != '\0'; i++) {
            Copy.Array[Index] = Add[i];
            Index++;
        }

        return Copy;
    }

    String operator+(char* Add) {
        String Copy(*this);

        int Size;
        for (Size = 0; Add[Size] != '\0'; Size++) {}

        Size += this->len();

        delete[] Copy.Array;
        Copy.Array = nullptr;

        Copy.Array = new char[Size + 1]; // Accounting For Null
        Copy.Array[Size] = '\0';

        int Index;

        for (Index = 0; Array[Index] != '\0'; Index++) {
            Copy.Array[Index] = Array[Index];
        }

        for (int i = 0; Add[i] != '\0'; i++) {
            Copy.Array[Index] = Add[i];
            Index++;
        }

        return Copy;
    }

    int StringToInt(char* CharArray) { // Helper Function That Converts String Into Numbers
        int NumResult = 0;

        if (CharArray == nullptr) {
            return 0;
        }

        for (int i = 0; CharArray[i] != '\0'; i++) {
            if (CharArray[i] < '0' || CharArray[i] > '9') {
                return -1; // Error
            }

            NumResult = NumResult * 10 + (CharArray[i] - '0');
        }

        return NumResult;
    }

    char* IntToString(int Num) { // Helper Function That Converts Numbers Into String

        if (Num == 0) {
            char* Result = new char[2];
            Result[0] = '0';
            Result[1] = '\0';
            return Result;
        }

        int TempNum = Num;
        int Size = 0;

        while (TempNum > 0) {
            Size++;
            TempNum /= 10;
        }

        char* Result = new char[Size + 1];

        int CurrentIndex = Size - 1;
        TempNum = Num;
        while (TempNum > 0) {
            Result[CurrentIndex] = (TempNum % 10) + '0';
            TempNum /= 10;
            CurrentIndex--;
        }

        Result[Size] = '\0';

        return Result;
    }

    String operator+(const int& Add) { // if the stored String is an integer e.g. “123” it adds the given integer into it and returns the answer. If not then returns “NaN”
        int Num = StringToInt(Array) + Add;

        if (StringToInt(Array) != -1) {
            String Copy(IntToString(Num));
            return Copy;
        }
        else {
            String Copy("NaN");
            return Copy;
        }
    }

    String remove(const String& Remove) { //removes a substring anywhere in the String
        String Result(*this);

        int Index = 0;

        for (int i = 0; Array[i] != '\0'; i++) {
            bool Match = true;

            for (int j = 0; j < Remove.len(); j++) {
                if (Array[i + j] != Remove.Array[j]) {
                    Match = false;
                    break;
                }
            }

            if (Match) {
                i += Remove.len() - 1;
                continue;
            }

            Result.Array[Index++] = Array[i];
        }

        Result.Array[Index] = '\0';
        return Result;
    }

    String remove(const char* Input) { //removes a substring anywhere in the String 
        String Result(*this);
        String Remove(Input);

        int Index = 0;

        for (int i = 0; Array[i] != '\0'; i++) {
            bool Match = true;

            for (int j = 0; j < Remove.len(); j++) {
                if (Array[i + j] != Remove.Array[j]) {
                    Match = false;
                    break;
                }
            }

            if (Match) {
                i += Remove.len() - 1;
                continue;
            }

            Result.Array[Index++] = Array[i];
        }

        Result.Array[Index] = '\0';
        return Result;
    }

    String remove(char* Input) { //removes a substring anywhere in the String
        String Result(*this);
        String Remove(Input);

        int Index = 0;
        int CheckIndex = 0;

        for (int i = 0; Array[i] != '\0'; i++) {
            if (Array[i] == Remove.Array[CheckIndex]) {
                CheckIndex++;
            }
            if (CheckIndex >= Remove.len()) {
                CheckIndex = 0;
                Index -= Remove.len();
            }
            else {
                Result.Array[Index] = Array[i];
                Index++;
            }
        }

        Result.Array[Index] = '\0';

        return Result;
    }

    String remove(const int& Remove) { // if the stored String is an integer e.g. “123” it subtracts the given integer into it and returns the answer. If not then returns “NaN”
        int Num = StringToInt(Array) - Remove;

        if (StringToInt(Array) != -1) {
            String temp(IntToString(Num));
            return temp;
        }
        else {
            String temp("NaN");
            return temp;
        }
    }

    bool operator==(const String& ToCheck) const {
        bool Equal = true;

        if (this->len() != ToCheck.len()) {
            return false;
        }

        for (int i = 0; i < ToCheck.len(); i++) {
            if (Array[i] != ToCheck.Array[i]) {
                Equal = false;
            }
        }

        return Equal;
    }

    bool operator==(const char* ToCheck)const {
        bool Equal = true;

        int Size;
        for (Size = 0; ToCheck[Size] != '\0'; Size++) {}

        if (this->len() != Size) {
            return false;
        }

        for (int i = 0; i < Size; i++) {
            if (Array[i] != ToCheck[i]) {
                Equal = false;
            }
        }

        return Equal;
    }

    bool operator==(char* ToCheck)const {
        bool Equal = true;

        int Size;
        for (Size = 0; ToCheck[Size] != '\0'; Size++) {}

        if (this->len() != Size) {
            return false;
        }

        for (int i = 0; i < Size; i++) {
            if (Array[i] != ToCheck[i]) {
                Equal = false;
            }
        }

        return Equal;
    }

    bool operator!() {
        if (Array[0] == '\0') {
            return true;
        }

        return false;
    }

    void operator+=(const String& Add) { //appends a new string into the same string
        String Copy(*this);

        int Size = Copy.len() + Add.len();

        delete[] Array;
        Array = nullptr;

        Array = new char[Size + 1]; // Accounting For Null
        Array[Size] = '\0';

        int Index;

        for (Index = 0; Copy.Array[Index] != '\0'; Index++) {
            Array[Index] = Copy.Array[Index];
        }

        for (int i = 0; Add.Array[i] != '\0'; i++) {
            Array[Index] = Add.Array[i];
            Index++;
        }
    }

    void operator+=(const char* Input) { //appends a new string into the same string
        String Copy(*this);
        String Add(Input);

        int Size = Copy.len() + Add.len();

        delete[] Array;
        Array = nullptr;

        Array = new char[Size + 1]; // Accounting For Null
        Array[Size] = '\0';

        int Index;

        for (Index = 0; Copy.Array[Index] != '\0'; Index++) {
            Array[Index] = Copy.Array[Index];
        }

        for (int i = 0; Add.Array[i] != '\0'; i++) {
            Array[Index] = Add.Array[i];
            Index++;
        }
    }

    void operator+=(char* Input) { //appends a new string into the same string
        String Copy(*this);
        String Add(Input);

        int Size = Copy.len() + Add.len();

        delete[] Array;
        Array = nullptr;

        Array = new char[Size + 1]; // Accounting For Null
        Array[Size] = '\0';

        int Index;

        for (Index = 0; Copy.Array[Index] != '\0'; Index++) {
            Array[Index] = Copy.Array[Index];
        }

        for (int i = 0; Add.Array[i] != '\0'; i++) {
            Array[Index] = Add.Array[i];
            Index++;
        }
    }

    void removesub(const String& Remove) { // removes the substring from the same string
        String Result(*this);

        int Index = 0;

        for (int i = 0; Result.Array[i] != '\0'; i++) {
            bool Match = true;

            for (int j = 0; j < Remove.len(); j++) {
                if (Result.Array[i + j] != Remove.Array[j]) {
                    Match = false;
                    break;
                }
            }

            if (Match) {
                i += Remove.len() - 1;
                continue;
            }

            Array[Index++] = Result.Array[i];
        }

        Array[Index] = '\0';
    }

    void removesub(const char* Input) { // removes the substring from the same string
        String Result(*this);
        String Remove(Input);

        int Index = 0;

        for (int i = 0; Result.Array[i] != '\0'; i++) {
            bool Match = true;

            for (int j = 0; j < Remove.len(); j++) {
                if (Result.Array[i + j] != Remove.Array[j]) {
                    Match = false;
                    break;
                }
            }

            if (Match) {
                i += Remove.len() - 1;
                continue;
            }

            Array[Index++] = Result.Array[i];
        }

        Array[Index] = '\0';
    }

    void removesub(char* Input) { // removes the substring from the same string
        String Result(*this);
        String Remove(Input);

        int Index = 0;

        for (int i = 0; Result.Array[i] != '\0'; i++) {
            bool Match = true;

            for (int j = 0; j < Remove.len(); j++) {
                if (Result.Array[i + j] != Remove.Array[j]) {
                    Match = false;
                    break;
                }
            }

            if (Match) {
                i += Remove.len() - 1;
                continue;
            }

            Array[Index++] = Result.Array[i];
        }

        Array[Index] = '\0';
    }

    String slice(const String& Param) {

        int Index = 0;
        int EndIndex = this->len();
        int IndexMulti = 1;

        int Temp = 0;
        int Sign = 1;
        int NumOperator = 0;

        bool Stored = false;

        for (int i = 0; Param.Array[i] != '\0'; i++) {
            if (Param.Array[i] == '-') {
                Sign = -1;
            }
            else if (Param.Array[i] >= '0' && Param.Array[i] <= '9') {
                Temp = Temp * 10 + (Param.Array[i] - '0');
                Stored = true;
            }
            if (Param.Array[i] == ':' || Param.Array[i + 1] == '\0') {
                if (Stored) {
                    if (NumOperator == 0) {
                        Index = Temp * Sign;
                    }
                    else if (NumOperator == 1) {
                        EndIndex = Temp * Sign;
                    }
                    else if (NumOperator == 2) {
                        IndexMulti = Temp * Sign;
                    }
                }
                NumOperator++;
                Temp = 0;
                Sign = 1;
                Stored = false;
            }
        }

        if (IndexMulti == 0) {
            IndexMulti = 1;
        }
        if (Index < 0) {
            Index += this->len();
        }
        if (EndIndex < 0) {
            EndIndex += this->len();
        }
        if (Index < 0) {
            Index = 0;
        }
        if (EndIndex > this->len()) {
            EndIndex = this->len();
        }

        if (Index >= EndIndex) {
            String temp("");
            return temp; // Return Empty
        }

        String Result(*this);

        int NewIndex = 0;

        if (IndexMulti >= 0) {
            for (int i = Index; i < EndIndex; i += IndexMulti) {
                Result.Array[NewIndex] = Array[i];
                NewIndex++;
            }
        }
        else {
            for (int i = EndIndex - 1; i >= Index; i += IndexMulti) {
                Result.Array[NewIndex] = Array[i];
                NewIndex++;
            }
        }

        Result.Array[NewIndex] = '\0';

        return Result;
    }


    String slice(const char* input) { // Performs slicing according to explanation below
        String Temp(input);
        return slice(Temp);
    }

    int len() {
        int Size;
        for (Size = 0; Array[Size] != '\0'; Size++) {}

        return Size;
    }

    int len() const { // Helper Function
        int Size;
        for (Size = 0; Array[Size] != '\0'; Size++) {}

        return Size;
    }

    void Print() { // Helper For Testing

        for (int i = 0; i < this->len();i++) {
            cout << Array[i];
        }

        cout << endl;
    }

    String lower() {
        String Copy(*this);

        for (int i = 0; i < this->len(); i++) {
            if (Copy.Array[i] >= 'A' && Copy.Array[i] <= 'Z') {
                Copy.Array[i] += 'a' - 'A';
            }
        }

        return Copy;
    }

    String upper() {
        String Copy(*this);

        for (int i = 0; i < this->len(); i++) {
            if (Copy.Array[i] >= 'a' && Copy.Array[i] <= 'z') {
                Copy.Array[i] += 'A' - 'a';
            }
        }

        return Copy;
    }

    String title() {
        String Copy(*this);

        for (int i = 0; i < this->len(); i++) {
            if (Copy.Array[i - 1] == ' ' || i == 0) {
                if (Copy.Array[i] >= 'a' && Copy.Array[i] <= 'z') {
                    Copy.Array[i] += 'A' - 'a';
                }
            }
            else if (Copy.Array[i] >= 'A' && Copy.Array[i] <= 'Z') {
                Copy.Array[i] += 'a' - 'A';
            }
        }

        return Copy;
    }

    String swapcase() {
        String Copy(*this);

        for (int i = 0; i < this->len(); i++) {
            if (Copy.Array[i] >= 'A' && Copy.Array[i] <= 'Z') {
                Copy.Array[i] += 'a' - 'A';
            }
            else if (Copy.Array[i] >= 'a' && Copy.Array[i] <= 'z') {
                Copy.Array[i] += 'A' - 'a';
            }
        }

        return Copy;
    }


    bool startsWith(const char* Input) {
        String Check(Input);
        return startsWith(Check);
    }

    bool startsWith(String& Check) {
        if (Check.len() > this->len()) {
            return false;
        }

        bool StartFlag = true;

        for (int i = 0; i < Check.len(); i++) {
            if (Array[i] != Check.Array[i]) {
                StartFlag = false;
                break;
            }
        }

        return StartFlag;
    }

    bool endsWith(const char* Input) {
        String Check(Input);
        return endsWith(Check);
    }

    bool endsWith(String& Check) {
        if (Check.len() > this->len()) {
            return false;
        }

        bool EndFlag = true;

        for (int i = 1; i <= Check.len(); i++) {
            if (Array[this->len() - i] != Check.Array[Check.len() - i]) {
                EndFlag = false;
                break;
            }
        }

        return EndFlag;
    }

    String replace(String& ToReplace, String& Replacement) {
        String Result(*this);

        delete[] Result.Array;
        Result.Array = nullptr;

        Result.Array = new char[this->len() + Replacement.len() * 20 + 1]; // Accounting For Null
        Result.Array[this->len() + Replacement.len() * 20] = '\0';

        int Index = 0;

        for (int i = 0; Array[i] != '\0'; i++) {
            bool Match = true;

            for (int j = 0; j < ToReplace.len(); j++) {
                if (Array[i + j] != ToReplace.Array[j]) {
                    Match = false;
                    break;
                }
            }

            if (Match) {
                i += ToReplace.len() - 1;

                for (int j = 0; j < Replacement.len();j++) {
                    Result.Array[Index] = Replacement.Array[j];
                    Index++;
                }

                continue;
            }

            Result.Array[Index++] = Array[i];
        }

        Result.Array[Index] = '\0';
        return Result;
    }

    String replace(const char* Input1, const char* Input2) {
        String ToReplace(Input1);
        String Replacement(Input2);
        return replace(ToReplace, Replacement);

    }

    String join(String& Add) {
        String Result(*this);

        delete[] Result.Array;
        Result.Array = nullptr;

        Result.Array = new char[this->len() + (this->len() - 1) * Add.len() + 1]; // Accounting For Null

        int Index = 0;

        for (int i = 0; i < this->len(); i++) {
            Result.Array[Index] = Array[i];
            Index++;
            if (i != this->len() - 1) {
                for (int j = 0; j < Add.len(); j++) {
                    Result.Array[Index] = Add.Array[j];
                    Index++;
                }
            }
        }

        Result.Array[Index] = '\0';

        return Result;
    }

    String join(const char* Input) {
        String Add(Input);
        return join(Add);
    }

    String join(char* Input) {
        String Add(Input);
        return join(Add);
    }

    String* split(String& Split, int& size) {
        size = 1;

        for (int i = 0; Array[i] != '\0'; i++) {
            bool Match = true;

            for (int j = 0; j < Split.len(); j++) {
                if (Array[i + j] != Split.Array[j]) {
                    Match = false;
                    break;
                }
            }

            if (Match) {
                size++;
                i += Split.len() - 1;
            }
        }

        String* SubArrays = new String[size];

        int NumSubArray = 0, Start = 0;

        for (int i = 0; Array[i] != '\0'; i++) {
            bool Match = true;

            for (int j = 0; j < Split.len(); j++) {
                if (Array[i + j] != Split.Array[j]) {
                    Match = false;
                    break;
                }
            }

            if (Match) {
                int SubLen = i - Start;
                SubArrays[NumSubArray].Array = new char[SubLen + 1];

                for (int k = 0; k < SubLen; k++) {
                    SubArrays[NumSubArray].Array[k] = Array[Start + k];
                }

                SubArrays[NumSubArray].Array[SubLen] = '\0';
                NumSubArray++;
                Start = i + Split.len();
                i += Split.len() - 1;
            }
        }

        int SubLen = this->len() - Start;

        SubArrays[NumSubArray].Array = new char[SubLen + 1];

        for (int k = 0; k < SubLen; k++) {
            SubArrays[NumSubArray].Array[k] = Array[Start + k];
        }

        SubArrays[NumSubArray].Array[SubLen] = '\0';

        return SubArrays;
    }


    String* split(const char* Input, int& size) {
        String Split(Input);
        return split(Split, size);
    }

    String* split(char* Input, int& size) {
        String Split(Input);
        return split(Split, size);
    }

    ~String() {
        delete[] Array;
        Array = nullptr;
    }
};
