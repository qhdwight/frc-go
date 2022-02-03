#pragma once
#include "ctre/configparams/ConfigConstants.h"

namespace ctre {
	namespace configparams {
		/** POD storage */
		class ConfigByteArray {
		public:
			const uint32_t kCapacity = 4096;

			ConfigByteArray() { /* empty */ }

			ConfigByteArray(const ConfigByteArray & rhs)
			{
				*this = rhs;
			}

			ConfigByteArray & operator = (const ConfigByteArray & rhs) 
			{
				Insert(rhs._bytes, rhs._sz);
				return *this;
			}
			~ConfigByteArray() { }
			/**
			 * Defaults configs to 0 (which matches firmware).
			 * Caller must pass in how many bytes configs need.
			 */
			int Reset(uint32_t sz)
			{
				int retval = 0;

				if (sz > kCapacity) {
					sz = kCapacity;

					retval = kConfig_InsufficientSz;
				}

				_sz = sz;

				memset(_bytes, 0, _sz);

				return retval;
			}

			int Insert(const uint8_t * src, uint32_t sz)
			{
				int retval = 0;

				if (sz > kCapacity) {
					sz = kCapacity;

					retval = kConfig_InsufficientSz;
				}

				_sz = sz;

				memcpy(_bytes, src, _sz);

				return retval;
			}
			void Clear()
			{
				Insert(nullptr, 0);
			}
			uint32_t Sz() const
			{
				return _sz;
			}
			const uint8_t * D() const
			{
				return _bytes;
			}
		public: // leave members public
			uint8_t _bytes[4096];
			uint32_t _sz = 0;
		};
	}
}
