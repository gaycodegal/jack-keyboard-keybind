#pragma once

#include <filesystem>
#include <fstream>
#include <optional>
#include <sstream>
#include <string>

extern int MIDI_ERROR;

/**
 * takes in things like "C#-2"
 * C#-2 -> (1)
 * Ab4 -> (80)
 * returns between 0 (C-2) - 127 (G8)
 *
 */
int string_to_midi(const std::string &note);

/**
 * Parses ints, if fail, return std::nullopt
 */
std::optional<int> parse_int(const std::string &s);

std::optional<std::string> read_file(const std::filesystem::path &path);
