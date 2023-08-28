#include "pch.h"
#include "Decompositor.h"



List<String^>^ Decompositor::GG(String^ str)
{
    Regex^ rgNumber = gcnew Regex("[+-]?[0-9]+([.]?[0-9]+)?", RegexOptions::IgnoreCase);
    Match^ match;
    List<String^>^ list = gcnew List<String^>();

    for (size_t i = 0; i < str->Length;)
    {
        String^ prev;
        Match^ match;
        if (str[i] >= '0' && str[i] <= '9')
        {
            match = rgNumber->Match(str, i);
            list->Add(match->Value);
            i += match->Length;
        }
        else
        {
            if (prev != "" && prev != "")
            {
                list->Add(str[i].ToString());
                i++;
                match = rgNumber->Match(str, i);
                list->Add(match->Value);
                i += match->Length;
            }
            else
            {
                if (str[i + 1] >= '0' && str[i + 1] <= '9')
                {
                    list->Add(str[i].ToString());
                    i++;
                    match = rgNumber->Match(str, i);
                    list->Add(match->Value);
                    i += match->Length;
                }
                else
                {
                    list->Add(str[i].ToString());
                    i++;
                }
            }
        }
    }

    //Match^ match = rgNumber->Match(str);
    //if (match->Length != 0) Console::WriteLine(match->Value);
    //else Console::WriteLine("Not Found");

    return list;
}
