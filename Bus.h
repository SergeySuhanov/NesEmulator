#pragma once
#include <cstdint>
#include <array>
#include "olc6502.h"
#include "olc2C02.h"
//#include <memory>

#include "Cartridge.h"

class Bus
{
public:
	Bus();
	~Bus();

public: // Devices on bus
	olc6502 cpu;

	// The 2c02 Picture Processing Unit
	olc2C02 ppu;
	// The Cartridge or "GamePak"
	std::shared_ptr<Cartridge> cart;

	uint8_t controller[2];

	// Fake RAM for this part of the series
	uint8_t cpuRam[2048];

public: // Bus read & write
	void cpuWrite(uint16_t addr, uint8_t data);
	uint8_t cpuRead(uint16_t addr, bool bReadOnly = false);

public: // System Interface
	void insertCartridge(const std::shared_ptr<Cartridge>& cartridge);
	void reset();
	void clock();

private:
	uint32_t nSystemClockCounter = 0;

	uint8_t controller_state[2];
};

