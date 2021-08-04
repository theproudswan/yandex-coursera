#include <string>
#include <list>
#include "test_runner.h"
using namespace std;

class Editor {
 public:
  // Реализуйте конструктор по умолчанию и объявленные методы
  Editor() = default;
  void Left(){
      if (cursor_position != text.begin())
        cursor_position--;
  }
  void Right(){
      if (cursor_position != text.end())
        cursor_position++;
  }
  void Insert(char token){
      text.insert(cursor_position, token);
  }
  void Cut(size_t tokens = 1){
      Copy(tokens);
      auto temp_cursor = cursor_position;
      while(tokens){
          if (++temp_cursor == text.end()) break;
          tokens--;
      }
      cursor_position = text.erase(cursor_position, temp_cursor);
  }
  void Copy(size_t tokens = 1){
     //buffer.clear();
     buffer = { cursor_position, next(cursor_position, tokens) };
  }
  void Paste(){
    //  text.insert(cursor_position, buffer.begin(), buffer.end());
      for(auto c : buffer) text.insert(cursor_position, c);
  }
  string GetText() const{
      ostringstream os;
      for(auto c : text){
          os << c;
      }
      return os.str();
  }
  private:
  list<char> text;
  list<char> buffer;
  list<char>::iterator cursor_position = text.begin();
};

void TypeText(Editor& editor, const string& text) {
  for(char c : text) {
    editor.Insert(c);
  }
}

void TestEditing() {
  {
    Editor editor;

    const size_t text_len = 12;
    const size_t first_part_len = 7;
    TypeText(editor, "hello, world");
    for(size_t i = 0; i < text_len; ++i) {
      editor.Left();
    }
    editor.Cut(first_part_len);
    for(size_t i = 0; i < text_len - first_part_len; ++i) {
      editor.Right();
    }
    TypeText(editor, ", ");
    editor.Paste();
    editor.Left();
    editor.Left();
    editor.Cut(3);
    
    ASSERT_EQUAL(editor.GetText(), "world, hello");
  }
  {
    Editor editor;
    
    TypeText(editor, "misprnit");
    editor.Left();
    editor.Left();
    editor.Left();
    editor.Cut(1);
    editor.Right();
    editor.Paste();
    
    ASSERT_EQUAL(editor.GetText(), "misprint");
  }
}

void TestReverse() {
  Editor editor;

  const string text = "esreveR";
  for(char c : text) {
    editor.Insert(c);
    editor.Left();
  }
  
  ASSERT_EQUAL(editor.GetText(), "Reverse");
}

void TestNoText() {
  Editor editor;
  ASSERT_EQUAL(editor.GetText(), "");
  
  editor.Left();
  editor.Left();
  editor.Right();
  editor.Right();
  editor.Copy(0);
  editor.Cut(0);
  editor.Paste();
  
  ASSERT_EQUAL(editor.GetText(), "");
}

void TestEmptyBuffer() {
  Editor editor;

  editor.Paste();
  TypeText(editor, "example");
  editor.Left();
  editor.Left();
  editor.Paste();
  editor.Right();
  editor.Paste();
  editor.Copy(0);
  editor.Paste();
  editor.Left();
  editor.Cut(0);
  editor.Paste();
  ASSERT_EQUAL(editor.GetText(), "example");
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestEditing);
  RUN_TEST(tr, TestReverse);
  RUN_TEST(tr, TestNoText);
  RUN_TEST(tr, TestEmptyBuffer);
  return 0;
}