"""
@author: Michael Rapp (michael.rapp.ml@gmail.com)
"""
from libcpp.memory cimport make_unique


cdef class InstanceSamplingFactory:
    """
    A wrapper for the pure virtual C++ class `IInstanceSamplingFactory`.
    """
    pass


cdef class InstanceSamplingWithReplacementFactory(InstanceSamplingFactory):
    """
    A wrapper for the C++ class `InstanceSamplingWithReplacementFactory`.
    """

    def __cinit__(self, float32 sample_size):
        """
        :param sample_size: The fraction of examples to be included in the sample (e.g. a value of 0.6 corresponds to
                            60 % of the available examples). Must be in (0, 1]
        """
        self.instance_sampling_factory_ptr = <unique_ptr[IInstanceSamplingFactory]>make_unique[InstanceSamplingWithReplacementFactoryImpl](
            sample_size)


cdef class InstanceSamplingWithoutReplacementFactory(InstanceSamplingFactory):
    """
    A wrapper for the C++ class `InstanceSamplingWithoutReplacementFactory`.
    """

    def __cinit__(self, float32 sample_size):
        """
        param sample_size: The fraction of examples to be included in the sample (e.g. a value of 0.6 corresponds to
                           60 % of the available examples). Must be in (0, 1)
        """
        self.instance_sampling_factory_ptr = <unique_ptr[IInstanceSamplingFactory]>make_unique[InstanceSamplingWithoutReplacementFactoryImpl](
            sample_size)


cdef class LabelWiseStratifiedSamplingFactory(InstanceSamplingFactory):
    """
    A wrapper for the C++ class `LabelWiseStratifiedSamplingFactory`.
    """

    def __cinit__(self, float32 sample_size):
        """
        param sample_size: The fraction of examples to be included in the sample (e.g. a value of 0.6 corresponds to
                           60 % of the available examples). Must be in (0, 1)
        """
        self.instance_sampling_factory_ptr = <unique_ptr[IInstanceSamplingFactory]>make_unique[LabelWiseStratifiedSamplingFactoryImpl](
            sample_size)


cdef class ExampleWiseStratifiedSamplingFactory(InstanceSamplingFactory):
    """
    A wrapper for the C++ class `ExampleWiseStratifiedSamplingFactory`.
    """

    def __cinit__(self, float32 sample_size):
        """
        param sample_size: The fraction of examples to be included in the sample (e.g. a value of 0.6 corresponds to
                           60 % of the available examples). Must be in (0, 1)
        """
        self.instance_sampling_factory_ptr = <unique_ptr[IInstanceSamplingFactory]>make_unique[ExampleWiseStratifiedSamplingFactoryImpl](
            sample_size)


cdef class NoInstanceSamplingFactory(InstanceSamplingFactory):
    """
    A wrapper for the C++ class `NoInstanceSamplingFactory`.
    """

    def __cinit__(self):
        self.instance_sampling_factory_ptr = <unique_ptr[IInstanceSamplingFactory]>make_unique[NoInstanceSamplingFactoryImpl]()
