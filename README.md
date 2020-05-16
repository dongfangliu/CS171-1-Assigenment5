# **Assignment 5** - Volume Rendering Using Ray-casting

## **Introduction**

In this assignment, you will be dealing with volume rendering, which is a very common rendering technique in industry for volume data. Volume data is a widely used as a type of data sources, such as CT data, smoke data and so on.

In this assignment, you are required to write a Volume Ray-caster. Compared to volume texture projection with the "over" operator, ray-casting method gives a much more detailed control for programmers to adjust the overall appearance. Implementing Ray-casting based volume rendering can also help you consolidate the basic knowledge of volume rendering. 

In the following, we will give you the specifics about what you need to accomplish, as well as some related guidelines in order to assist your programming.

---

## **Things to be done**

Though there's a lot of work have to do to implement the volume renderer, we provide a  framework that give the basic functionality (such as volume data reading, voxel coordinating, ray-volume intersection, camera ray generation). 

You only have to complete the core parts.

**[must]** A basic volume ray-caster requires you to implement 6 components:

1. Volume pre-processing 

   1. gradient computing

2. Sampler

   1. fixed step or adaptive

3. Interpolator 

   1. Nearest Neighbour Interpolator
   2. Trilinear Interpolator

4. Classifier 

   1. Customize your transfer function
   2. Local Phong Shading model 

5. Compositor 

   1. Front to Back Compositor Scheme
   2. Back to Front Compositor Scheme

6. Renderer

   A renderer which assemble all the components today and output the result image.

**[Optional]** If either of below is completed, you will optional points. You should explain your implementation and show the comparison of results (before/after) in your report.

+ Add in-scattering using phase function 
+ Add volume shadow 

**Some specific requirements:**

- Since we are working on CPU, we don't really ask for a very splendid image. You can render a relatively small-sized image, like around 500x500. However, we do not recommend resolutions below this, because in that case we might not be able to see your results clearly.
- Your rendering result of the volume should have relatively clear structure and little noise. Your score will also be adjusted based on the beautifulness of your rendering result

---

## **Submission & demonstration**

After you finish the project, you need demonstrate your work to TAs. Since now most of us have been back to school, we will have a specific face-to-face check time. However, <u>the source code</u> and <u>a technical report</u> are still required to submit via GitHub Classroom in time.

 **Submission deadline**: TBD

 **Demonstration time**: TBD

### **Requirements for technical report:**

For technical report, we require you to do it with [LaTex](https://www.latex-project.org/), and you can use [TeXstudio](https://www.texstudio.org/) to facilitate your editing. The [LaTex](https://www.latex-project.org/) template for your technical report is provided within the repository of code template. In the report, you should describe your main work and essential results.
<u>Notice</u>:

- You need to show the final rendering result displaying all the required items and show comparisons with different choices  respectively (ways of interpolation, different step-size and different composition scheme) in the report.
- If you choose to do the optional part, please specify the process in the report.
- The report must <u>follow the LaTex template</u> and be written <u>in English</u> only.
- Failure to present your work clearly could lead to doubts about plagiarism or grade deduction.
- Be aware that it is NOT a place to display large chunks of codes.
- Put the <u>PDF version</u> of your report in the <u>root directory</u> of your repository. Otherwise, your report might not be graded.
- Failure to satisfy the above requirements could lead to grade deduction.

### **Requirements for source code:**
Make sure that the source code you submitted is written by yourself independently. In serious cases, if similar codes are found, we might consider possibilities of plagiarism.

---

## **Grading rules**

- The **[must]** items describe the requirements that you must meet in your project. If you fulfilled that perfectly according to the requirements and demonstrated your work successfully via the recorded video, you will get all the scores for the programming part. However, if you do not submit a valid source code, your grade of this assignment will be 0.
- You can choose to do the **[optional]** item, and if you choose to do it, you will get additional scores based on the additional work you have done. But the maximum additional score will not exceed 20% of the entire score of this assignment.
- In addition to programming, you need to submit a technical report specifying the details of your implementation: what you have done and how you achieved them. Not submitting these files will have your grade for demonstration and report deduced.
- If we find out any form of plagiarism (including source code, video and technical report) in your work, your score of the assignment will be 0.
- Late submission of your assignment may subject to score deduction. Please refer to [Late hand-in policy](http://faculty.sist.shanghaitech.edu.cn/faculty/liuxp/course/cg1/) for details.

---

## **Notice before you start**

- We provided a skeleton code that might help you to achieve the requirements, which you will see when you accepted the assignment on GitHub classroom. Though we have tested the skeleton code to the best of our abilities, it might still have bugs hidden. When you believe something is wrong with the skeleton code, don't hesitate to contact TAs or post the problem in Piazza.
- There are recording of  offline tutorials that might get you started, which you can download from the same place that you download the lecture videos. There might be some differences between the skeleton code in the tutorial videos and the actual skeleton code. Please follow the requirements on this page, not the video, for the reason that the skeleton code in the video is somewhat outdated and only used for demonstration
- Debug option is for debugging purposes and we recommend that you use release option at all times when you are eager to see the result.
- You are not allowed to use any libraries in the project unless it is provided in the skeleton code

---

## **Instructions**

Most explanation of code structures will be presented in offline tutorials and recorded in videos. Here we only give some specification and guidance to make your life easier.

1. gradient computing 

   You should fill **computeGradients()** in **src/volume.cpp**. You shall consider to use [central difference](https://en.wikipedia.org/wiki/Finite_difference) to compute the gradients for all volume data in `volume.raw_data`  and store it as a member variable `graident` in `volumeData`.

2. Sampler

   You are free to use fixed step or adaptive when sampling along the ray. However, it is much more reasonable to follow the sampling theorem that was descripted on *page 43 of lecture19*.

3. Interpolator 

   You are required to implement two kinds of interpolator ([Nearest Neighbour Interpolator](https://en.wikipedia.org/wiki/Nearest-neighbor_interpolation) and [Trilinear Interpolator](https://en.wikipedia.org/wiki/Trilinear_interpolation)) and compare rendering results. The main idea is to get importance weight of  a data point based on its position in a voxel and interpolate other attributes (density,gradient) using the weight. Using trilinear interpolator shall eliminate artifacts.

4. Classifier 

   Here are two sub tasks:

   1. Customize your transfer function
   2. Local Phong Shading model 

   Classifier works as a mapper from the volume data to optics data, giving the color and opacity that will be used in the composition process.  To determine the color, you shall consider emission and in-scattering. You could model the emission using phong lighting model (taking the gradient direction as normal). The in-scattering belongs to the optional part which can be neglected here.

   Then, you have to decide the opacity. Opacity is the opposite concept of transparency. When opacity equals to 0, it means no energy will be absorbed. Higher density generally implies high absorption. You shall design and tune your own transfer function.

   Besides, you should find a way to make use of gradient to enhance smoke structure.

   You should be clear that  we are doing the discrete form of  calculus integration, so the energy and absorption should also be related with your step-size to correctly approximate as a Riemann Sum.

5. Compositor 

   You are required to implement two composition scheme (Front to Back and Back To Front ) and compare rendering results.  Here you can refer to lecture18. 

6. Renderer

   To volume rendering, you has to first show a ray and decides the start point and end point through intersection with the volume. 

   Then, you shall sample a point and get its position. 

   After that, interpolate density and gradient with its voxel data (`interpolator.interpolate(position,volume.getVoxel(position)`).

   Now it's time to map the volume data into optics data.

   Finally you could use your compositor to take in color and opacity from the optics data.

   Then you will sample next point and repeat above process.

---

## **Expected results**

You are free to render one image or more. To download more data, click here.

Here's a single frame.

![](README.assets/foward_pre.png)

Here's a gif of 150 frames.

![](README.assets/test.gif)







