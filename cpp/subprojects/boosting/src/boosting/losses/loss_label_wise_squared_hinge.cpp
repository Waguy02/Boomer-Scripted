#include "boosting/losses/loss_label_wise_squared_hinge.hpp"


namespace boosting {

    static inline void updateGradientAndHessian(bool trueLabel, float64 predictedScore, float64* gradient,
                                                float64* hessian) {
        if (trueLabel) {
            if (predictedScore < 1) {
                *gradient = (predictedScore - 1);
            } else {
                *gradient = 0;
            }
        } else {
            if (predictedScore > 0) {
                *gradient = predictedScore;
            } else {
                *gradient = 0;
            }
        }

        *hessian = 1;
    }

    static inline float64 evaluatePrediction(bool trueLabel, float64 predictedScore) {
        if (trueLabel) {
            if (predictedScore < 1) {
                return (1 - predictedScore) * (1 - predictedScore);
            } else {
                return 0;
            }
        } else {
            if (predictedScore > 0) {
                return predictedScore * predictedScore;
            } else {
                return 0;
            }
        }
    }

    LabelWiseSquaredHingeLoss::LabelWiseSquaredHingeLoss()
        : AbstractLabelWiseLoss(&updateGradientAndHessian, &evaluatePrediction) {

    }

}
