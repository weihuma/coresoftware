/**
 * @file trackbase/TrkrDefs.h
 * @author D. McGlinchey
 * @date June 2018
 * @brief Namespace with Trkr key types and utility functions
 */
#ifndef TRACKBASE_TRKRDEFUTIL_H
#define TRACKBASE_TRKRDEFUTIL_H

#ifdef __CINT__
#include <limits.h>
#include <stdint.h>
#else
#include <climits>
#include <cstdint>
#endif
#include <iostream>

/**
 * @brief Define a namespace for Trkr typedefs
 */
namespace TrkrDefs
{
  /// Key types
  typedef uint32_t hitkey;      // 32 bit TrkrHit key type
  typedef uint32_t hitsetkey;   // 32 bit TrkrHitSet key type
  typedef uint64_t cluskey;     // 64 but TrkrCluster id type
  typedef uint32_t clushitkey;  // 32 bit hit id type in TrkrCluster
  
#ifndef __CINT__
  
  /// Max values for keys (used as defaults or invalid values)
  static hitkey HITKEYMAX __attribute__((unused)) = ULONG_MAX;
  static hitsetkey HITSETKEYMAX __attribute__((unused)) = ULONG_MAX;
  static cluskey CLUSKEYMAX __attribute__((unused)) = ULLONG_MAX;
  static clushitkey CLUSHITKEYMAX __attribute__((unused)) = ULONG_MAX;

  // hitsetkey layout:
  //  common upper 16 bits
  //   24 - 32  tracker id
  //   16 - 24  layer
  static const unsigned int kBitShiftTrkrId __attribute__((unused)) = 24;  // 32 - 8
  static const unsigned int kBitShiftLayer __attribute__((unused)) = 16;   // bitshift_trackerid - 8

  // cluskey layour
  //  hitsetkey upper 32 bits
  //  cluster id lower 32 bits
  static const unsigned int kBitShiftClusId __attribute__((unused)) = 32;
  
#endif
  
  /// Enumeration for tracker id to easily maintain consistency
  enum TrkrId
  {
    mvtxId = 0,
    inttId = 1,
    tpcId = 2
  };
  
  
  /// Print the bits for each key type
  void printBits(const TrkrDefs::hitsetkey key, std::ostream& os = std::cout);
  void printBits(const TrkrDefs::cluskey key, std::ostream& os = std::cout);
  // void print_bits(const TrkrDefs::hitkey key, std::ostream& os = std::cout);
  
  /// Get the tracker ID from either key type
  uint8_t getTrkrId(const TrkrDefs::hitsetkey key);
  uint8_t getTrkrId(const TrkrDefs::cluskey key);

  /// Get the layer number from either key type
  uint8_t getLayer(const TrkrDefs::hitsetkey key);
  uint8_t getLayer(const TrkrDefs::cluskey key);

  /// Get the lower 32 bits for cluster keys only
  uint32_t getClusIndex(const TrkrDefs::cluskey key);

  /// generate the common upper 16 bits for hitsetkey
  TrkrDefs::hitsetkey genHitSetKey(const TrkrDefs::TrkrId trkrId, const char lyr);

  /// Get the upper 32 bits from cluster keys
  uint32_t getHitSetKeyFromClusKey(const TrkrDefs::cluskey key);

  /// Get a valid low / hi range for hitsetkey given tracker id & layer
  TrkrDefs::hitsetkey getHitSetKeyLo(const TrkrDefs::TrkrId trkrId);
  TrkrDefs::hitsetkey getHitSetKeyHi(const TrkrDefs::TrkrId trkrId);
  TrkrDefs::hitsetkey getHitSetKeyLo(const TrkrDefs::TrkrId trkrId, const char lyr);
  TrkrDefs::hitsetkey getHitSetKeyHi(const TrkrDefs::TrkrId trkrId, const char lyr);

  /// Get a valid low / hi range for cluskey given tracker id & layer
  TrkrDefs::cluskey getClusKeyLo(const TrkrDefs::TrkrId trkrId);
  TrkrDefs::cluskey getClusKeyHi(const TrkrDefs::TrkrId trkrId);
  TrkrDefs::cluskey getClusKeyLo(const TrkrDefs::TrkrId trkrId, const char lyr);
  TrkrDefs::cluskey getClusKeyHi(const TrkrDefs::TrkrId trkrId, const char lyr);

}

#endif  //TRACKBASE_TRKRDEFUTIL_H
