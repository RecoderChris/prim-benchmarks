#ifndef _COMMON_H_
#define _COMMON_H_

#define ROUND_UP_TO_MULTIPLE_OF_2(x)    ((((x) + 1)/2)*2)
#define ROUND_UP_TO_MULTIPLE_OF_8(x)    ((((x) + 7)/8)*8)
#define ROUND_UP_TO_MULTIPLE_OF_64(x)   ((((x) + 63)/64)*64)

#define setBitF(val, idx) (val) |= (1 << (idx))
#define isSetF(val, idx)  ((val) & (1 << (idx)))

static inline void setBit(uint64_t* vec, int idx) {
    vec[idx / 64] |= (1ULL << (idx % 64));
}

static inline int isSet(const uint64_t* bitvec, uint64_t index) {
    return (bitvec[index / 64] >> (index % 64)) & 1ULL;
}

struct DPUParams {
    uint32_t dpuNumNodes; /* The number of nodes assigned to this DPU */
    uint32_t numNodes; /* Total number of nodes in the graph  */
    uint32_t dpuStartNodeIdx; /* The index of the first node assigned to this DPU  */
    uint32_t dpuNodePtrsOffset; /* Offset of the node pointers */
    uint32_t level; /* The current BFS level */
    uint32_t dpuNodePtrs_m;
    uint32_t dpuNeighborIdxs_m;
    uint32_t dpuNodeLevel_m;
    uint32_t dpuVisited_m;
    uint32_t dpuCurrentFrontier_m;
    uint32_t dpuNextFrontier_m;
};

#endif

