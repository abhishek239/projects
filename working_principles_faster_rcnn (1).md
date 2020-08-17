# Faster R-CNN

* This is a system containing mainly two modules
    *  Deep fully convolutional network that proposes regions i.e *Region Proposal Networks*(RPN).
    *  *Fast R-CNN* detector that uses proposed regions.
* This implementation is faster than fast R-CNN because of better proposal computation by RPN.
* This is because the selective search is replaced which is a slower technique.
* The output convolution layer of RPN is shared with Fast R-CNN in next step.
* 4-step alternating training is implemented to learn shared features via alternating optimization.
* The flowchart of how faster R-CNN works is given below.  
![faster R-CNN](https://gitlab.iotiot.in/shunya/products/object-detection-/uploads/7d54d983dafac0dc2a7f9568de23d241/Faster_RCNN_flowchart.png)

# Region Proposal Networks (RPN)

* Input is an object and output is a rectangular object proposal with objectness score.
* To generate region proposals, a small network is slided over the convolutional feature map output by the last shared convolutional layer.
* This small network takes an nxn spatial window of the input convolutional feature map as input and will be mapped to lower dimensional feature.
* This feature is fed into two sibling fully-connected layers namely box regression(*reg*) and box classification(*cls*) layer.
* At each sliding-window location, we simultaneously predict multiple region proposals, where the number of maximum possible proposals for each location is denoted as k.

![anchors](https://gitlab.iotiot.in/shunya/products/object-detection-/uploads/7702ef0566ca02dd7351ce96bddec866/rpn.JPG)
### 1.Anchors
* The k proposals are parametrized relative to k reference boxes called **Anchors**.
* Cls layer has 2k scores that estimate probability of object or not object for each proposal.
* Reg layer has 4k outputs encoding the coordinates of k boxes.
* Anchors are **translation invariant** i.e if objects are translated in an image then the same function should be able to predict the proposal in both the locations.
* Design of anchors addresses multiple scales and aspect ratios.

### 2.Loss function
* Loss function sums the loss of cls layer and reg layer.
* Both losses are calculated for each anchor and summed up.
* These losses are normalized and reg loss is weighted by lambda but the results are insensitive to these.
* It is assumed to have a positive label to 2 kinds of anchors and remaining anchors are given 0 label.
    * anchors with highest Intersection-over-Union overlap with a ground-truth box
    * anchors with IoU overlap greater than 0.7 with a ground-truth box.
* In loss of reg layer only those anchors are considered whose label is positive mentioned as above.
* In the loss of each layer log loss is considered.

### 3.Training RPN
* The RPN can be trained end-to-end by backpropagation and stochastic gradient descent (SGD).


