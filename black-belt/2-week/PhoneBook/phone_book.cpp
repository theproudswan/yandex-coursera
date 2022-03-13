#include "address_book.h"
#include "contact.pb.h"

#include <algorithm>

using namespace std;

struct NameComparator {
  bool operator()(const Contact& lhs, const Contact& rhs) const {
    return lhs.name < rhs.name;
  }

  bool operator()(const Contact& lhs, std::string_view rhs) const {
    return lhs.name < rhs;
  }

  bool operator()(std::string_view lhs, const Contact& rhs) const {
    auto [lp, rp] = std::mismatch(lhs.begin(), lhs.end(), rhs.name.begin(), rhs.name.end());
    return lp != lhs.end() && rp != rhs.name.end() && *lp < *rp;
  }
};

AddressBook::AddressBook(std::vector<Contact> contacts)
  : contacts_(std::move(contacts))
{
  std::sort(begin(contacts_), end(contacts_), NameComparator());
}

void AddressBook::SaveTo(std::ostream& output) const {
  AddressBookSerialize::ContactList result;
  for (const Contact& c : contacts_) {
    auto& serialized_person = *result.add_contact();
    serialized_person.set_name(c.name);
    if (c.birthday) {
      auto& birthday = *serialized_person.mutable_birthday();
      birthday.set_year(c.birthday->year);
      birthday.set_month(c.birthday->month);
      birthday.set_day(c.birthday->day);
    }
    for (const string& phone_number : c.phones) {
      serialized_person.add_phone_number(phone_number);
    }
  }

  result.SerializeToOstream(&output);
}

AddressBook DeserializeAddressBook(std::istream& input) {
  AddressBookSerialize::ContactList contacts;
  contacts.ParseFromIstream(&input);

  vector<Contact> result;
  result.reserve(contacts.contact_size());
  for (auto& item : *contacts.mutable_contact()) {
    Contact& current = result.emplace_back();
    current.name = std::move(*item.mutable_name());
    if (item.has_birthday()) {
      current.birthday = Date{item.birthday().year(), item.birthday().month(), item.birthday().day()};
    }
    for (auto& phone_number : *item.mutable_phone_number()) {
      current.phones.push_back(std::move(phone_number));
    }
  }

  return AddressBook(std::move(result));
}

AddressBook::ContactRange AddressBook::FindByNamePrefix(std::string_view name_prefix) const {
  auto range = std::equal_range(contacts_.cbegin(), contacts_.cend(), name_prefix, NameComparator());
  return {range.first, range.second};
}