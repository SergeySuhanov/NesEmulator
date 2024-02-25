#pragma once
#include <cstdint>
class Cartridge
{
public:
	Cartridge();
	~Cartridge();

	// Communication with Main Bus
	bool cpuRead(uint16_t addr, uint8_t& data);
	bool cpuWrite(uint16_t addr, uint8_t data);

	// Communication with PPU Bus
	bool ppuRead(uint16_t addr, uint8_t& data);
	bool ppuWrite(uint16_t addr, uint8_t data);
};

