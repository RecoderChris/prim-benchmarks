#!/bin/bash

make clean
echo "======"
echo "Peak performance"
# NR_DPUS=2500 NR_TASKLETS=1 make all
NR_DPUS=64 NR_TASKLETS=1 make all
for data in R18-16.el loc-gowalla.el;do
    result_dir=result_cloud/performance/1D_dense_push/${data}
    # result_dir=result_cloud/performance/sparse_push/${data}
    # result_dir=result_cloud/performance/dense_push/${data}
    # result_dir=result_cloud/performance/dense_push_cache/${data}
    mkdir -p ${result_dir}
    for i in {1..5}; do
        echo "Run $i for $data"
        ./bin/host_code -v 1 -f /mnt/data_nvme_2/zhangxinmiao/graph_data2/${data} > ${result_dir}/run_${i}.log
        # ./bin/host_code -v 1 -f ~/${data} -s 0 > ${result_dir}/run_${i}.log
    done
    # ./bin/host_code -v 1 -f /mnt/data_nvme_2/zhangxinmiao/graph_data2/${data} -s 0 >> ${result_dir}/${data}.log
done