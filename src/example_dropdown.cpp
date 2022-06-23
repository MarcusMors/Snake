// Copyright (C) 2022 José Enrique Vilca Campana
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include <string>  // for basic_string, string, allocator
#include <vector>  // for vector

#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Dropdown, Horizontal, Vertical
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive

int main(int argc, const char* argv[]) {
  using namespace ftxui;

  std::vector<std::string> entries = {
      "tribute",     "clearance", "ally",        "bend",        "electronics",
      "module",      "era",       "cultural",    "sniff",       "nationalism",
      "negotiation", "deliver",   "figure",      "east",        "tribute",
      "clearance",   "ally",      "bend",        "electronics", "module",
      "era",         "cultural",  "sniff",       "nationalism", "negotiation",
      "deliver",     "figure",    "east",        "tribute",     "clearance",
      "ally",        "bend",      "electronics", "module",      "era",
      "cultural",    "sniff",     "nationalism", "negotiation", "deliver",
      "figure",      "east",
  };

  int selected_1 = 0;
  int selected_2 = 0;
  int selected_3 = 0;
  int selected_4 = 0;

  auto layout = Container::Vertical({
      Container::Horizontal({
          Dropdown(&entries, &selected_1),
          Dropdown(&entries, &selected_2),
      }),
      Container::Horizontal({
          Dropdown(&entries, &selected_3),
          Dropdown(&entries, &selected_4),
      }),
  });

  auto screen = ScreenInteractive::FitComponent();
  screen.Loop(layout);
}

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.
