

#include "yellow_pages.h"

#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

#define ADD_FIELD(field) { \
  auto it = max_element(begin(signals), end(signals), [&](const auto& lhs, const auto& rhs){ \
    int p1_prior = providers.at(lhs.provider_id()).priority(); \
    int p2_prior = providers.at(rhs.provider_id()).priority(); \
    bool has_add1 = lhs.company().has_##field(); \ 
    bool has_add2 = rhs.company().has_##field(); \
    if (has_add1 != has_add2) return has_add1 < has_add2; \
    return p1_prior < p2_prior; \
  }); \
  if(it->company().has_##field()){ \
    *result.mutable_##field() = it->company().field(); \ 
  } \
}  


#define ADD_REPEATED(field, class_name, set_cmp) { \
    auto it = max_element(signals.begin(), signals.end(), [&](const auto& lhs, const auto& rhs) { \
		bool has_add1 = lhs.company().field##_size(); \
		bool has_add2 = rhs.company().field##_size(); \
		int p1_prior = providers.at(lhs.provider_id()).priority(); \
		int p2_prior = providers.at(rhs.provider_id()).priority(); \
		if (has_add1 != has_add2) return has_add1 < has_add2; \
		return p1_prior < p2_prior; \
		}); \
	int max_prior = providers.at(it->provider_id()).priority(); \
	std::set<class_name, set_cmp> uniques; \
	for (const auto& signal : signals) { \
		int prior = providers.at(signal.provider_id()).priority(); \
		if (prior == max_prior) { \
			for (int i = 0; i < signal.company().field##_size(); ++i) { \
				uniques.insert(signal.company().field(i)); \
			} \
		} \
	} \
	for (auto& el : uniques) { \
		*result.add_##field() = el; \
	} \
}

#define RETURN_CMP(field)  \
  if (lhs.field() != rhs.field()) return lhs.field() < rhs.field();

namespace YellowPages {
  // using Signals = std::vector<Signal>;
  // using Providers = std::unordered_map<uint64_t, Provider>;

  struct NameCmp {
    bool operator() (const Name& lhs, const Name& rhs) const {
      RETURN_CMP(type); 
      RETURN_CMP(value);
      return false;
    }
  };

  struct PhoneCmp{
    bool operator() (const Phone& lhs, const Phone& rhs) const {
      RETURN_CMP(formatted);
      RETURN_CMP(type);
      RETURN_CMP(country_code);
      RETURN_CMP(local_code);
      RETURN_CMP(number);
      RETURN_CMP(extension);
      RETURN_CMP(description);

      return false;
    }
  };

  struct UrlCmp{
    bool operator() (const Url& lhs, const Url& rhs) const {
      RETURN_CMP(value);
      return false;
    }
  };
  // Объединяем данные из сигналов об одной и той же организации
  Company Merge(const Signals& signals, const Providers& providers){
    Company result;
    ADD_FIELD(address);
    ADD_FIELD(working_time);

    ADD_REPEATED(names, Name, NameCmp);
    ADD_REPEATED(phones, Phone, PhoneCmp)
    ADD_REPEATED(urls, Url, UrlCmp);

    return result;
  }

}
