#pragma once

#include <iostream>
#include <unordered_map>
#include <string>
#include <string_view>

using namespace std;

namespace Ini {
    pair<string_view, string_view> Split(string_view line, char by);

    using Section = unordered_map<string, string>;

    class Document {
    public:
        Section& AddSection(string name);
        const Section& GetSection(const string& name) const;
        size_t SectionCount() const;

    private:
        unordered_map<string, Section> sections;
    };

    Document Load(istream& input);
}