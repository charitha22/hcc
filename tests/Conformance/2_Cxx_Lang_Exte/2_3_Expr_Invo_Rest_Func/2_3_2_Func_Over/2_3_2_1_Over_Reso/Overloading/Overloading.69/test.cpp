// Copyright (c) Microsoft
// All rights reserved
// Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
// THIS CODE IS PROVIDED *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS FOR A PARTICULAR PURPOSE, MERCHANTABLITY OR NON-INFRINGEMENT.
// See the Apache Version 2.0 License for specific language governing permissions and limitations under the License.
/// <tags>P0</tags>
/// <summary>Test conversion when matching</summary>

// RUN: %cxxamp %s -o %t.out && %t.out

#include <stdio.h>

class c
{
public:
    void f(int &v) [[cpu, hc]]
    {
        v = 1;
    }

    void f(float &f) 
    {
        
    }
};

bool test() 
{
    bool passed = true;
    
    c o;

    int v = 0;

    o.f(v);

    if (v != 1)
        passed = false;

    return passed;
}

int main(int argc, char **argv)
{
    bool passed = true;

    passed = test();

    return passed ? 0 : 1;

}

