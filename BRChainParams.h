//
//  BRChainParams.h
//
//  Created by Aaron Voisine on 1/10/18.
//  Copyright (c) 2019 breadwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRChainParams_h
#define BRChainParams_h

#include "BRMerkleBlock.h"
#include <assert.h>

typedef struct {
    uint32_t height;
    UInt256 hash;
    uint32_t timestamp;
    uint32_t target;
} BRCheckPoint;

typedef struct {
    const char * const *dnsSeeds; // NULL terminated array of dns seeds
    uint16_t standardPort;
    uint32_t magicNumber;
    uint64_t services;
    int (*verifyDifficulty)(const BRMerkleBlock *block, const BRMerkleBlock *previous, uint32_t transitionTime);
    const BRCheckPoint *checkpoints;
    size_t checkpointsCount;
} BRChainParams;

static const char *BRMainNetDNSSeeds[] = {
	"seed.deutsche-emark.de.", 
    "185.194.142.165",
    "88.98.228.14",
    "54.36.143.147",
    "195.211.155.193",
    "44.144.145.146", NULL
};

static const char *BRTestNetDNSSeeds[] = {
        "testseed@deutsche-emark.de", NULL
};

// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRMainNetCheckpoints[] = {
    {       0, uint256("00000ac7a13fffb72c10f6fd9a773dcf3e8388b8ffc359cee2483b1236ebcda1"), 1381515983, 0x1e0fffff },
    {  100000, uint256("0000000000000d09b191be5c3c0a9c080a5437346687160188ada2aa9f7cfb01"), 1393597725, 0x1a257902 },
    {  150000, uint256("0000000000000aefb0a2462732100c40efdce53fe27ba5c1d3d693c14415feac"), 1399683112, 0x1a31239d },
    {  200000, uint256("0000000000002889989080aac405f02a9feb54e461d7cddd92cf1ca8d8b84cc8"), 1405763791, 0x1a3dbf44 },
    {  240000, uint256("00000000000007bd9af865b57c6640317b8035e935bb4e6b126c8780ac4e5a38"), 1410691636, 0x1a4f6392 },
    {  300000, uint256("0000000000000140339a853ffe40e16aa3d379375b224a29231b4fccec9ab4e5"), 1418075826, 0x1a0fdb09 },
    {  300000, uint256("0000000000000140339a853ffe40e16aa3d379375b224a29231b4fccec9ab4e5"), 1418075826, 0x1a0fdb09 },
    {  400001, uint256("00000000000005b19c24a5ca800b9e495cbca611e2227609ea59ac24d6cbc550"), 1429024857, 0x1a0a77a7 },
    {  500004, uint256("87a3ba99a9eeea9f1745b88dbbb6fc4da22de5643eb1ca3a9984a1069d2865ee"), 1439469156, 0x1d2f5ef5 },
    {  600001, uint256("87456ae77dedb647689622a6f1d9073f3f3c38243c690a23b7d8e302f6db8a3f"), 1449822011, 0x1d2baf2c },
    {  640002, uint256("5bd76721290d4aa3c0aa46df0c39d85b339ab2b83be0bed6d356c0354550f1bf"), 1453910361, 0x1c564059 },
    {  700000, uint256("43f6f487555f41b304a05c85e10bbffa6ff23d17169428fee336c9af768dc406"), 1460133338, 0x1d14b5eb },
    {  800000, uint256("0000000000000e617a11d8e34c1e63449e6b9c8ddb718c81e22f584240997079"), 1467481810, 0x1a107ef4 },
    {  900000, uint256("00000000000008e12316dddb12ec4eae37b084d45dc1a6f20f9817f973dea830"), 1473532452, 0x1a09e468 },
    { 1000000, uint256("00000000000002eabd7836eaab5ca86525731d2c3e2f01add80b9ea5b772cd20"), 1479583187, 0x1a053771 },
    { 1100000, uint256("0000000000000402bdf8ccede644b7a7f2f1e20e593d5146eb7da6703841de8c"), 1485636487, 0x1a04a0c5 },
    { 1200000, uint256("000000000000017f54f4549172a47a59376e72e44c7a829c75b86050eaa6e564"), 1491690318, 0x1a02c574 },
    { 1300000, uint256("d9c98ec64f964f59a192c63d1af4d8449cd68e7e526626a7c98bfdf090b0dc1b"), 1497741312, 0x1c00867c },
    { 1400000, uint256("9cf9760ed875a43e263aeeea6ad526f79e3a8021fe30b93344f80913b5cb357a"), 1503795376, 0x1b72b711 },
    { 1500000, uint256("394006e5a85a4c2da1b4f86113939ae3d5795778ba0806f7d5d47e380776c2ab"), 1509841920, 0x1b488653 },
    { 1600000, uint256("c63599c6bb36f290f5dbce453fad5515185a5334f0ce3b352ebeac4c8139fe83"), 1515884320, 0x1b270164 },
    { 1650000, uint256("0000000000000085686f93994b1a30cf9da2657a3e8de64ed4cd6b39b35b7e46"), 1518908673, 0x1a00a52b },
    { 1700000, uint256("000000000000003ceab618aeb96326be3774d8f65045b2ab2abb68627387a145"), 1521932620, 0x195de6e1 },
    { 1800000, uint256("7c76863365da81252bd4d3137e04f839933b2b4fc86fbfd2c7933db8197f798a"), 1528010352, 0x1b3fb1ee },
    { 1900000, uint256("0000000000000030c337eea1d0b9a5c8378bf0dd86b14e293a3bd458ea0dd29d"), 1534143387, 0x195282fb },
    { 2000000, uint256("f6a45a54b97c9be99d3925151b334cbe3cc1f13172ea90fda4e48087ac139bc1"), 1540287056, 0x1b415db3 },
    { 2010000, uint256("000000000000003ae521dea80daa2143f7c543f4806ca9ca7e268b6e50ddabb6"), 1540899800, 0x1a00e1e1 },
    { 2020000, uint256("0b4112feae4c8eda3bc9182d85c0718e09bf4f146d4c7a8a2d823f8c4454e93f"), 1541507136, 0x1b3ae2d9 },
    { 2030000, uint256("0000000000000039821e57375ceeba3bf8e793f0d82a5d22c6a0cf7a3107308d"), 1542109646, 0x193c0234 },
    { 2040000, uint256("0000000000000030eacc728ee1d6e1728d62d86cc038134b91df3647fdf072c8"), 1542715659, 0x194c598e }	
};

static const BRCheckPoint BRTestNetCheckpoints[] = {
    {       0, uint256("0000fa2783bec51b4039b29d61bd2bff61be74cdd4404f582b5b3f8fd3d15921"), 1381515983, 0x1f00ffff }
};

static int BRTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRMerkleBlock *previous, uint32_t transitionTime)
{
    int r = 1;
    
    assert(block != NULL);
    
    if (! previous || !UInt256Eq(block->prevBlock, previous->blockHash) || block->height != previous->height + 1)
        r = 0;
    
    return r;
}

static const BRChainParams BRMainNetParams = {
    BRMainNetDNSSeeds,
    5556,       // standardPort
    0xe5e9e8e4, // magicNumber
    0,          // services
    BRMerkleBlockVerifyDifficulty,
    BRMainNetCheckpoints,
    sizeof(BRMainNetCheckpoints)/sizeof(*BRMainNetCheckpoints)
};

static const BRChainParams BRTestNetParams = {
    BRTestNetDNSSeeds,
    15556,      // standardPort
    0xdeb9c3fe, // magicNumber
    0,          // services
    BRTestNetVerifyDifficulty,
    BRTestNetCheckpoints,
    sizeof(BRTestNetCheckpoints)/sizeof(*BRTestNetCheckpoints)
};

#endif // BRChainParams_h
