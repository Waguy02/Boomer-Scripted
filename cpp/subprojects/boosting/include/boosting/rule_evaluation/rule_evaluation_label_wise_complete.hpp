/*
 * @author Michael Rapp (michael.rapp.ml@gmail.com)
 */
#pragma once

#include "boosting/rule_evaluation/rule_evaluation_label_wise.hpp"


namespace boosting {

    /**
     * Allows to create instances of the class `LabelWiseCompleteRuleEvaluationFactory`.
     */
    class LabelWiseCompleteRuleEvaluationFactory final : public ILabelWiseRuleEvaluationFactory {

        private:

            float64 l1RegularizationWeight_;

            float64 l2RegularizationWeight_;

        public:

            /**
             * @param l1RegularizationWeight    The weight of the L1 regularization that is applied for calculating the
             *                                  scores to be predicted by rules
             * @param l2RegularizationWeight    The weight of the L2 regularization that is applied for calculating the
             *                                  scores to be predicted by rules
             */
            LabelWiseCompleteRuleEvaluationFactory(float64 l1RegularizationWeight, float64 l2RegularizationWeight);

            std::unique_ptr<IRuleEvaluation<DenseLabelWiseStatisticVector>> create(
                const DenseLabelWiseStatisticVector& statisticVector,
                const CompleteIndexVector& indexVector) const override;

            std::unique_ptr<IRuleEvaluation<DenseLabelWiseStatisticVector>> create(
                const DenseLabelWiseStatisticVector& statisticVector,
                const PartialIndexVector& indexVector) const override;

    };

}
