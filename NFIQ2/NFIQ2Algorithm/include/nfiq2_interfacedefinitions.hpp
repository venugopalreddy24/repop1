#ifndef NFIQ2_INTERFACEDEFINITIONS_HPP_
#define NFIQ2_INTERFACEDEFINITIONS_HPP_

#include <nfiq2_data.hpp>

#include <string>
#include <vector>

namespace NFIQ2 {
/**
 * Interpretation of quality features that may indicated corrective measures
 * for subsequent captures of the same subject.
 */
namespace ActionableQualityFeedback {
/** Identifiers for actionable feedback values. */
namespace IDs {
/**
 * The image is blank or the contrast is too low.
 *
 * @details
 * The mean gray level appears white.
 */
extern const std::string EmptyImageOrContrastTooLow;
/** Standard deviation of gray levels in image indicates uniformity. */
extern const std::string UniformImage;
/**
 * Number of minutia in image.
 *
 * @note
 * Equivalent to QualityFeatures::Minutiae::Count.
 */
extern const std::string FingerprintImageWithMinutiae;
/** Number of pixels in the computed foreground. */
extern const std::string SufficientFingerprintForeground;
}

/**
 * Thresholds corresponding to IDs.
 *
 * @details
 * Comparing the values of IDs with Thresholds may indicate a corrective action
 * for subsequent captures of the same subject.
 */
namespace Thresholds {
/** Threshold value for IDs::EmptyImageOrContrastTooLow. */
extern const double EmptyImageOrContrastTooLow;
/** Threshold value for IDs::UniformImage. */
extern const double UniformImage;
/** Threshold value for IDs::FingerprintImageWithMinutiae. */
extern const double FingerprintImageWithMinutiae;
/** Threshold value for IDs::SufficientFingerprintForeground. */
extern const double SufficientFingerprintForeground;
}
}

/** Identifiers of individual quality features. */
namespace QualityFeatureIDs {
/** Frequency of the sinusoid following the ridge-valley structure. */
namespace FrequencyDomainAnalysis {
/**
 * Local quality values represented as a histogram.
 *
 * @details
 * Bins for the histogram are defined in the NFIQ 2 Report.
 */
namespace Histogram {
/** First of ten histogram bin boundaries. */
extern const char Bin0[];
/** Second of ten histogram bin boundaries. */
extern const char Bin1[];
/** Third of ten histogram bin boundaries. */
extern const char Bin2[];
/** Fourth of ten histogram bin boundaries. */
extern const char Bin3[];
/** Fifth of ten histogram bin boundaries. */
extern const char Bin4[];
/** Sixth of ten histogram bin boundaries. */
extern const char Bin5[];
/** Seventh of ten histogram bin boundaries. */
extern const char Bin6[];
/** Eighth of ten histogram bin boundaries. */
extern const char Bin7[];
/** Ninth of ten histogram bin boundaries. */
extern const char Bin8[];
/** Tenth of ten histogram bin boundaries. */
extern const char Bin9[];
}

/** Mean of local quality value. */
extern const char Mean[];
/** Standard deviation of local quality values. */
extern const char StdDev[];
}
/**
 * Measures relative to minutiae detected within the image using the integrated
 * feature extractor, FingerJet FX OSE.
 */
namespace Minutiae {
/** Number of minutiae in the image. */
extern const char Count[];

/**
 * Number of minutiae lying in a 200x200 pixel rectangle centered at the center
 * of mass of the locations of all detected minutia.
 */
extern const char CountCOM[];

/**
 * Percentage of minutiae whose quality value, as determined by Grayscale::Mean
 * of a 32x32 pixel region centered on the minutiae, is between 0-0.5.
 *
 * @see Grayscale::Mean
 */
extern const char QualityMu2[];

/**
 * Percentage of minutiae whose quality value, as determined by the Orientation
 * Certainty Level of a 32x32 pixel region centered on the minutiae, is above
 * 80.
 *
 * @see OrientationCertainty
 */
extern const char QualityOCL80[];
}

/** Measures based on the foreground area of the image. */
namespace RegionOfInterest {
/**
 * Mean grayscale value of the number of 32x32 pixel regions having at least 1
 * pixel in the ROI.
 */
extern const char Mean[];

/** Sum of coherence values over all 16x16 pixel regions within the ROI. */
extern const char CoherenceSum[];

/**
 * Average of coherence values over all 16x16 pixel regions within the ROI.
 *
 * @details
 * This is computed as RegionOfInterest::CoherenceSum / (number of 16x16 pixel
 * regions that contain at least 1 pixel within the ROI).
 *
 * @see CoherenceSum
 */
extern const char CoherenceMean[];
}

/** Measure of the clarity of ridge and valleys. */
namespace LocalClarity {
/**
 * Local quality values represented as a histogram.
 *
 * @details
 * Bins for the histogram are defined in the NFIQ 2 Report
 */
namespace Histogram {
/** First of ten histogram bin boundaries. */
extern const char Bin0[];
/** Second of ten histogram bin boundaries. */
extern const char Bin1[];
/** Third of ten histogram bin boundaries. */
extern const char Bin2[];
/** Fourth of ten histogram bin boundaries. */
extern const char Bin3[];
/** Fifth of ten histogram bin boundaries. */
extern const char Bin4[];
/** Sixth of ten histogram bin boundaries. */
extern const char Bin5[];
/** Seventh of ten histogram bin boundaries. */
extern const char Bin6[];
/** Eighth of ten histogram bin boundaries. */
extern const char Bin7[];
/** Ninth of ten histogram bin boundaries. */
extern const char Bin8[];
/** Tenth of ten histogram bin boundaries. */
extern const char Bin9[];
}

/** Mean of local quality value. */
extern const char Mean[];
/** Standard deviation of local quality values. */
extern const char StdDev[];
}

/** Measure of the gray levels of the image. */
namespace Grayscale {
/** Arithmetic mean of the image. */
extern const char Mean[];
/** Arithmetic mean of per-block means of the image. */
extern const char MeanBlock[];
}

/**
 * Measure of the strength of the energy concentration along the dominant
 * ridge flow orientation.
 */
namespace OrientationCertainty {
/**
 * Local quality values represented as a histogram.
 *
 * @details
 * Bins for the histogram are defined in the NFIQ 2 Report
 */
namespace Histogram {
/** First of ten histogram bin boundaries. */
extern const char Bin0[];
/** Second of ten histogram bin boundaries. */
extern const char Bin1[];
/** Third of ten histogram bin boundaries. */
extern const char Bin2[];
/** Fourth of ten histogram bin boundaries. */
extern const char Bin3[];
/** Fifth of ten histogram bin boundaries. */
extern const char Bin4[];
/** Sixth of ten histogram bin boundaries. */
extern const char Bin5[];
/** Seventh of ten histogram bin boundaries. */
extern const char Bin6[];
/** Eighth of ten histogram bin boundaries. */
extern const char Bin7[];
/** Ninth of ten histogram bin boundaries. */
extern const char Bin8[];
/** Tenth of ten histogram bin boundaries. */
extern const char Bin9[];
}

/** Mean of local quality value. */
extern const char Mean[];
/** Standard deviation of local quality values. */
extern const char StdDev[];
}

/**
 * Measure of the ridge flow continuity, based on the absolute orientation
 * difference between a block in its 8-neighborhood.
 */
namespace OrientationFlow {
/**
 * Local quality values represented as a histogram.
 *
 * @details
 * Bins for the histogram are defined in the NFIQ 2 Report
 */
namespace Histogram {
/** First of ten histogram bin boundaries. */
extern const char Bin0[];
/** Second of ten histogram bin boundaries. */
extern const char Bin1[];
/** Third of ten histogram bin boundaries. */
extern const char Bin2[];
/** Fourth of ten histogram bin boundaries. */
extern const char Bin3[];
/** Fifth of ten histogram bin boundaries. */
extern const char Bin4[];
/** Sixth of ten histogram bin boundaries. */
extern const char Bin5[];
/** Seventh of ten histogram bin boundaries. */
extern const char Bin6[];
/** Eighth of ten histogram bin boundaries. */
extern const char Bin7[];
/** Ninth of ten histogram bin boundaries. */
extern const char Bin8[];
/** Tenth of ten histogram bin boundaries. */
extern const char Bin9[];
}

/** Mean of local quality value. */
extern const char Mean[];
/** Standard deviation of local quality values. */
extern const char StdDev[];
}

/** Measure of the consistency of ridge and valley widths. */
namespace RidgeValleyUniformity {
/**
 * Local quality values represented as a histogram.
 *
 * @details
 * Bins for the histogram are defined in the NFIQ 2 Report
 */
namespace Histogram {
/** First of ten histogram bin boundaries. */
extern const char Bin0[];
/** Second of ten histogram bin boundaries. */
extern const char Bin1[];
/** Third of ten histogram bin boundaries. */
extern const char Bin2[];
/** Fourth of ten histogram bin boundaries. */
extern const char Bin3[];
/** Fifth of ten histogram bin boundaries. */
extern const char Bin4[];
/** Sixth of ten histogram bin boundaries. */
extern const char Bin5[];
/** Seventh of ten histogram bin boundaries. */
extern const char Bin6[];
/** Eighth of ten histogram bin boundaries. */
extern const char Bin7[];
/** Ninth of ten histogram bin boundaries. */
extern const char Bin8[];
/** Tenth of ten histogram bin boundaries. */
extern const char Bin9[];
}

/** Mean of local quality value. */
extern const char Mean[];
/** Standard deviation of local quality values. */
extern const char StdDev[];
}
}

/** This type represents a structure for timing information of features. */
typedef struct feature_speed_t {
	/** The name of the feature group. */
	std::string featureIDGroup;
	/**
	 * The unique IDs of the features that are used for determining the
	 * speed.
	 */
	std::vector<std::string> featureIDs;
	/** The speed of feature data computation in milliseconds. */
	double featureSpeed;
} QualityFeatureSpeed;
} // namespace NFIQ

#endif /* NFIQ2_INTERFACEDEFINITIONS_HPP_ */
