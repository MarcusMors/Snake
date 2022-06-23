#include <iostream>
#include <limits>
#include <random>

#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/screen/string.hpp"

int main(void) {
  using Seed = std::random_device;
  using Engine = std::default_random_engine;
  // long, unsigned short, unsigned int, unsigned long, or unsigned long long
  using int_type = int;
  using Distribution = std::uniform_int_distribution<int_type>;

  Seed seed;
  Engine engine{seed()};
  // const int_type max = std::numeric_limits<int_type>::max();
  // const int_type min = std::numeric_limits<int_type>::min();
  const int_type max = 4;
  const int_type min = 0;

  Distribution distribution(min, max);
  enum direction : int_type {
    left = 0,
    up = 1,
    right = 2,
    down = 3,
  };
  auto generate_random_number = [&]() { return distribution(engine); };

  using namespace ftxui;

  auto summary = [&] {
    auto content = vbox({
        hbox({text(L"- done:   "), text(L"3") | bold}) | color(Color::Green),
        hbox({text(L"- active: "), text(L"2") | bold}) | color(Color::RedLight),
        hbox({text(L"- queue:  "), text(L"9") | bold}) | color(Color::Red),
    });
    return window(text(L" Summary "), content);
  };

  auto document =  //
      vbox({
          hbox({
              summary(),
              summary(),
              summary() | flex,
          }),
          summary(),
          summary(),
      });

  // Limit the size of the document to 80 char.
  document = document | size(WIDTH, LESS_THAN, 80);

  auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
  Render(screen, document);

  std::cout << screen.ToString() << '\0' << std::endl;

  return EXIT_SUCCESS;
}
