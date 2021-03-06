/*
 * @author Lukas Johannes Eberle (lukasjohannes.eberle@stud.tu-darmstadt.de)
 * @author Michael Rapp (michael.rapp.ml@gmail.com)
 */
#pragma once

#include "common/data/vector_bit.hpp"
#include "common/rule_refinement/rule_refinement.hpp"
#include "common/rule_refinement/rule_refinement_callback.hpp"
#include "common/binning/threshold_vector.hpp"
#include "common/sampling/weight_vector.hpp"


/**
 * A vector that stores the weights of individual bins.
 */
typedef BitVector BinWeightVector;

/**
 * Allows to find the best refinements of existing rules, which result from adding a new condition that correspond to a
 * certain feature. The thresholds that may be used by the new condition result from the boundaries between the bins
 * that have been created using a binning method.
 *
 * @tparam T The type of the vector that provides access to the indices of the labels for which the refined rule is
 *           allowed to predict
 */
template<typename T>
class ApproximateRuleRefinement final : public IRuleRefinement {

    private:

        const T& labelIndices_;

        uint32 featureIndex_;

        bool nominal_;

        const IWeightVector& weights_;

        std::unique_ptr<IRuleRefinementCallback<ThresholdVector, BinWeightVector>> callbackPtr_;

        std::unique_ptr<Refinement> refinementPtr_;

    public:

        /**
         * @param labelIndices      A reference to an object of template type `T` that provides access to the indices of
         *                          the labels for which the refined rule is allowed to predict
         * @param featureIndex      The index of the feature, the new condition corresponds to
         * @param nominal           True, if the feature at index `featureIndex` is nominal, false otherwise
         * @param weights           A reference to an object of type `IWeightVector` that provides access to the weights
         *                          of individual training examples
         * @param callbackPtr       An unique pointer to an object of type `IRuleRefinementCallback` that allows to
         *                          retrieve the bins for a certain feature
         */
        ApproximateRuleRefinement(const T& labelIndices, uint32 featureIndex, bool nominal,
                                  const IWeightVector& weights, std::unique_ptr<IRuleRefinementCallback<ThresholdVector,
                                  BinWeightVector>> callbackPtr);

        void findRefinement(const AbstractEvaluatedPrediction* currentHead) override;

        std::unique_ptr<Refinement> pollRefinement() override;

};
