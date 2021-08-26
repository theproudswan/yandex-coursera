#include "ini.h"

using namespace std;

namespace Ini{
    pair<string_view, string_view> Split(string_view line, char by) { // Разделяет строку на две части 
        size_t pos = line.find(by);
        string_view left = line.substr(0, pos);

        if (pos < line.size() && pos + 1 < line.size()) {
            return {left, line.substr(pos + 1)};
        } else {
            return {left, string_view()};
        }
    }
    using Section = unordered_map<string, string>;

        Section& Document::AddSection(string name){
            return sections[name];
        }
        const Section& Document::GetSection(const string& name) const{
            return sections.at(name);
        }
        size_t Document::SectionCount() const{
            return sections.size();
        }

    Document Load(istream& input){
        Document result;
        Section *current_section = nullptr;
        for (string line; getline(input, line);){
            if (!line.empty()){
                if(line[0] == '['){
                    current_section = &result.AddSection(line.substr(1, line.size() - 2));
                } else {
                    auto pos = line.find('=');
                    current_section->insert(Split(line, '='));
                }
            }
        }
        return result;
    }
} // End of namespace "Ini"